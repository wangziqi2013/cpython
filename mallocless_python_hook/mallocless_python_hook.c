
#include "mallocless_python_hook.h"

#ifdef __cplusplus
extern "C" {
#endif

void mallocless_python_hook_PyMem_RawMalloc(uint64_t size, void *ptr) {
  //(void)size; (void)ptr;
  zsim_magic_op_malloc((int)size, (uint64_t)ptr);
  zsim_magic_op_resume_sim();
  return;
}

void mallocless_python_hook_PyMem_RawCalloc(uint64_t count, uint64_t size, void *ptr) {
  //(void)count; (void)size; (void)ptr;
  zsim_magic_op_calloc((int)count, (int)size, (uint64_t)ptr);
  zsim_magic_op_resume_sim();
  return;
}

void mallocless_python_hook_PyMem_RawRealloc(void *old_ptr, uint64_t size, void *new_ptr) {
  //(void)old_ptr; (void)size; (void)new_ptr;
  zsim_magic_op_realloc((uint64_t)old_ptr, (int)size, (uint64_t)new_ptr);
  zsim_magic_op_resume_sim();
  return;
}

void mallocless_python_hook_PyMem_RawFree(void *ptr) {
  //(void)ptr;
  zsim_magic_op_free((uint64_t)ptr);
  zsim_magic_op_resume_sim();
  return;
}

void mallocless_python_hook_PyObject_Malloc(uint64_t size, void *ptr) {
  zsim_magic_op_malloc((int)size, (uint64_t)ptr);
  zsim_magic_op_resume_sim();
  return;
}

void mallocless_python_hook_PyObject_Calloc(uint64_t count, uint64_t size, void *ptr) {
  zsim_magic_op_calloc((int)count, (int)size, (uint64_t)ptr);
  zsim_magic_op_resume_sim();
  return;
}

void mallocless_python_hook_PyObject_Realloc(void *old_ptr, uint64_t size, void *new_ptr) {
  zsim_magic_op_realloc((uint64_t)old_ptr, (int)size, (uint64_t)new_ptr);
  zsim_magic_op_resume_sim();
  return;
}

void mallocless_python_hook_PyObject_Free(void *ptr) {
  zsim_magic_op_free((uint64_t)ptr);
  zsim_magic_op_resume_sim();
  return;
}

static type_gen_alloc_t *type_gen_alloc_head = NULL;
static type_gen_alloc_t *type_gen_alloc_tail = NULL;
uint64_t type_gen_alloc_count = 0UL;

void malloc_python_hook_Python_start() {
  printf("========== Python Start ==========\n");
  printf("==================================\n");
  return;
}

void malloc_python_hook_Python_end() {
  // Print statistics
  printf("========== Python End ==========\n");
  printf("type_gen_alloc_count = %lu\n", type_gen_alloc_count);
  type_gen_alloc_t *curr = type_gen_alloc_head;
  const char filename = "malloc_python_hook_type_gen_alloc.csv";
  FILE *fp = fopen(filename, "w");
  if(fp == NULL) {
    printf("Cannot open file for write: \"%s\"\n", filename);
  }
  while(curr->next != NULL) {
    fprintf(fp, "%s,%d,%d,%d,%d,%lu", 
      curr->name, curr->base_size, curr->item_size, curr->total_size, curr->item_count, curr->ret
      );
    curr = curr->next;
  }
  fclose(fp);
  printf("================================\n");
  return;
}

void malloc_python_hook_type_gen_alloc(
    const char *name, int base_size, int item_size, int total_size, int item_count, uint64_t ret) {
  type_gen_alloc_t *alloc = (type_gen_alloc_t *)malloc(sizeof(type_gen_alloc_t *));
  if(alloc == NULL) {
    printf("malloc_python_hook_type_gen_alloc() out of memory\n");
    exit(1);
  }
  alloc->next = NULL;
  alloc->name = malloc(strlen(name) + 1);
  if(alloc->name == NULL) {
    printf("malloc_python_hook_type_gen_alloc() out of memory\n");
    exit(1);
  }
  strcpy(alloc->name, name);
  alloc->base_size = base_size;
  alloc->item_size = item_size;
  alloc->total_size = total_size;
  alloc->item_count = item_count;
  alloc->ret = ret;
  if(type_gen_alloc_head == NULL) {
    type_gen_alloc_head = type_gen_alloc_tail = alloc;
  } else {
    type_gen_alloc_tail->next = alloc;
    type_gen_alloc_tail = alloc;
  }
  // Also increment the counter
  type_gen_alloc_count++;
  return;
}

#ifdef __cplusplus
}
#endif
