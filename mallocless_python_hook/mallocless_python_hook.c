
#include "mallocless_python_hook.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PYALLOC_OBJECT_MALLOC   1
#define PYALLOC_OBJECT_CALLOC   2
#define PYALLOC_OBJECT_REALLOC  3
#define PYALLOC_OBJECT_FREE     4

#define PYALLOC_PYMEM_MALLOC      10
#define PYALLOC_PYMEM_CALLOC      20
#define PYALLOC_PYMEM_REALLOC     30
#define PYALLOC_PYMEM_FREE        40

#define PYALLOC_RAW_MALLOC      100
#define PYALLOC_RAW_CALLOC      200
#define PYALLOC_RAW_REALLOC     300
#define PYALLOC_RAW_FREE        400

typedef struct pyalloc_struct_t {
  int type;
  uint64_t arg1, arg2;
  uint64_t ret;
  struct pyalloc_struct_t *next;
} pyalloc_t;

typedef struct type_gen_alloc_struct_t {
  char *name;
  int base_size, item_size, total_size;
  int item_count;
  uint64_t ret;
  struct type_gen_alloc_struct_t *next;
} type_gen_alloc_t;

int alloc_nest_level = 0;

void malloc_python_hook_enter_alloc() {
  alloc_nest_level++;
  return;
}

void malloc_python_hook_leave_alloc() {
  alloc_nest_level--;
  return;
}

static pyalloc_t *pyalloc_head = NULL;
static pyalloc_t *pyalloc_tail = NULL;

uint64_t pyalloc_raw_malloc_count = 0UL;
uint64_t pyalloc_raw_calloc_count = 0UL;
uint64_t pyalloc_raw_realloc_count = 0UL;
uint64_t pyalloc_raw_free_count = 0UL;

uint64_t pyalloc_pymem_malloc_count = 0UL;
uint64_t pyalloc_pymem_calloc_count = 0UL;
uint64_t pyalloc_pymem_realloc_count = 0UL;
uint64_t pyalloc_pymem_free_count = 0UL;

uint64_t pyalloc_object_malloc_count = 0UL;
uint64_t pyalloc_object_calloc_count = 0UL;
uint64_t pyalloc_object_realloc_count = 0UL;
uint64_t pyalloc_object_free_count = 0UL;

void malloc_python_hook_pyalloc_stat_print() {
  printf("  pyalloc_raw_malloc_count = %lu\n", pyalloc_raw_malloc_count);
  printf("  pyalloc_raw_calloc_count = %lu\n", pyalloc_raw_calloc_count);
  printf("  pyalloc_raw_realloc_count = %lu\n", pyalloc_raw_realloc_count);
  printf("  pyalloc_raw_free_count = %lu\n", pyalloc_raw_free_count);
  printf("-----\n");
  printf("  pyalloc_pymem_malloc_count = %lu\n", pyalloc_pymem_malloc_count);
  printf("  pyalloc_pymem_calloc_count = %lu\n", pyalloc_pymem_calloc_count);
  printf("  pyalloc_pymem_realloc_count = %lu\n", pyalloc_pymem_realloc_count);
  printf("  pyalloc_pymem_free_count = %lu\n", pyalloc_pymem_free_count);
  printf("-----\n");
  printf("  pyalloc_object_malloc_count = %lu\n", pyalloc_object_malloc_count);
  printf("  pyalloc_object_calloc_count = %lu\n", pyalloc_object_calloc_count);
  printf("  pyalloc_object_realloc_count = %lu\n", pyalloc_object_realloc_count);
  printf("  pyalloc_object_free_count = %lu\n", pyalloc_object_free_count);
  pyalloc_t *curr = pyalloc_head;
  const char *filename = "malloc_python_hook_py_alloc.csv";
  FILE *fp = fopen(filename, "w");
  if(fp == NULL) {
    printf("Cannot open file for write: \"%s\"\n", filename);
    exit(1);
  }
  while(curr->next != NULL) {
    fprintf(fp, 
      "%d,%lu,%lu,%lu\n", 
      curr->type, curr->arg1, curr->arg2, curr->ret
      );
    curr = curr->next;
  }
  fclose(fp);
  return;
}

void malloc_python_hook_pyalloc_add(int type, uint64_t arg1, uint64_t arg2, uint64_t ret) {
  pyalloc_t *alloc = (pyalloc_t *)malloc(sizeof(pyalloc_t));
  if(alloc == NULL) {
    printf("mallocless_python_hook_PyObject_Malloc() out of memory\n");
    exit(1);
  }
  alloc->next = NULL;
  alloc->type = type;
  alloc->arg1 = arg1;
  alloc->arg2 = arg2;
  alloc->ret = ret;
  if(pyalloc_head == NULL) {
    pyalloc_head = pyalloc_tail = alloc;
  } else {
    pyalloc_tail->next = alloc;
    pyalloc_tail = alloc;
  }
  switch(type) {
    case PYALLOC_RAW_MALLOC: pyalloc_raw_malloc_count++; break;
    case PYALLOC_RAW_CALLOC: pyalloc_raw_calloc_count++; break;
    case PYALLOC_RAW_REALLOC: pyalloc_raw_realloc_count++; break;
    case PYALLOC_RAW_FREE: pyalloc_raw_free_count++; break;
    //
    case PYALLOC_PYMEM_MALLOC: pyalloc_pymem_malloc_count++; break;
    case PYALLOC_PYMEM_CALLOC: pyalloc_pymem_calloc_count++; break;
    case PYALLOC_PYMEM_REALLOC: pyalloc_pymem_realloc_count++; break;
    case PYALLOC_PYMEM_FREE: pyalloc_pymem_free_count++; break;
    //
    case PYALLOC_OBJECT_MALLOC: pyalloc_object_malloc_count++; break;
    case PYALLOC_OBJECT_CALLOC: pyalloc_object_calloc_count++; break;
    case PYALLOC_OBJECT_REALLOC: pyalloc_object_realloc_count++; break;
    case PYALLOC_OBJECT_FREE: pyalloc_object_free_count++; break;
    default: break;
  }
  return;
}

void mallocless_python_hook_RawMalloc(uint64_t size, void *ptr) {
  malloc_python_hook_pyalloc_add(PYALLOC_RAW_MALLOC, size, 0, (uint64_t)ptr);
  return;
}

void mallocless_python_hook_RawCalloc(uint64_t count, uint64_t size, void *ptr) {
  malloc_python_hook_pyalloc_add(PYALLOC_RAW_CALLOC, count, size, (uint64_t)ptr);
  return;
}

void mallocless_python_hook_RawRealloc(void *old_ptr, uint64_t size, void *new_ptr) {
  malloc_python_hook_pyalloc_add(PYALLOC_RAW_REALLOC, (uint64_t)old_ptr, size, (uint64_t)new_ptr);
  return;
}

void mallocless_python_hook_RawFree(void *ptr) {
  malloc_python_hook_pyalloc_add(PYALLOC_RAW_FREE, (uint64_t)ptr, 0UL, 0UL);
  return;
}

//////////////////////////////////////////
//////////////////////////////////////////
//////////////////////////////////////////

void mallocless_python_hook_PyMem_Malloc(uint64_t size, void *ptr) {
  malloc_python_hook_pyalloc_add(PYALLOC_PYMEM_MALLOC, size, 0, (uint64_t)ptr);
  return;
}

void mallocless_python_hook_PyMem_Calloc(uint64_t count, uint64_t size, void *ptr) {
  malloc_python_hook_pyalloc_add(PYALLOC_PYMEM_CALLOC, count, size, (uint64_t)ptr);
  return;
}

void mallocless_python_hook_PyMem_Realloc(void *old_ptr, uint64_t size, void *new_ptr) {
  malloc_python_hook_pyalloc_add(PYALLOC_PYMEM_REALLOC, (uint64_t)old_ptr, size, (uint64_t)new_ptr);
  return;
}

void mallocless_python_hook_PyMem_Free(void *ptr) {
  malloc_python_hook_pyalloc_add(PYALLOC_PYMEM_FREE, (uint64_t)ptr, 0UL, 0UL);
  return;
}

//////////////////////////////////////////
//////////////////////////////////////////
//////////////////////////////////////////

void mallocless_python_hook_PyObject_Malloc(uint64_t size, void *ptr) {
  malloc_python_hook_pyalloc_add(PYALLOC_OBJECT_MALLOC, size, 0, (uint64_t)ptr);
  return;
}

void mallocless_python_hook_PyObject_Calloc(uint64_t count, uint64_t size, void *ptr) {
  malloc_python_hook_pyalloc_add(PYALLOC_OBJECT_CALLOC, count, size, (uint64_t)ptr);
  return;
}

void mallocless_python_hook_PyObject_Realloc(void *old_ptr, uint64_t size, void *new_ptr) {
  malloc_python_hook_pyalloc_add(PYALLOC_OBJECT_REALLOC, (uint64_t)old_ptr, size, (uint64_t)new_ptr);
  return;
}

void mallocless_python_hook_PyObject_Free(void *ptr) {
  malloc_python_hook_pyalloc_add(PYALLOC_OBJECT_FREE, (uint64_t)ptr, 0UL, 0UL);
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
  malloc_python_hook_type_gen_stat_print();
  malloc_python_hook_pyalloc_stat_print();
  printf("================================\n");
  return;
}

// Print stats and dump the CSV file
void malloc_python_hook_type_gen_stat_print() {
  printf("type_gen_alloc_count = %lu\n", type_gen_alloc_count);
  type_gen_alloc_t *curr = type_gen_alloc_head;
  const char *filename = "malloc_python_hook_type_gen_alloc.csv";
  FILE *fp = fopen(filename, "w");
  if(fp == NULL) {
    printf("Cannot open file for write: \"%s\"\n", filename);
    exit(1);
  }
  while(curr->next != NULL) {
    fprintf(fp, 
      "%s,%d,%d,%d,%d,%lu\n", 
      curr->name, curr->base_size, curr->item_size, curr->total_size, curr->item_count, curr->ret
      );
    curr = curr->next;
  }
  fclose(fp);
  return;
}

void malloc_python_hook_type_gen_alloc(
    const char *name, int base_size, int item_size, int total_size, int item_count, uint64_t ret) {
  type_gen_alloc_t *alloc = (type_gen_alloc_t *)malloc(sizeof(type_gen_alloc_t));
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
