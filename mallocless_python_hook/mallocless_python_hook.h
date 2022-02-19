
#ifndef _MALLOCLESS_PYTHON_HOOK_H
#define _MALLOCLESS_PYTHON_HOOK_H

#include <stdint.h>
#include "zsim_magic_ops.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct type_gen_alloc_struct_t {
  const char *name;
  int base_size, item_size, total_size;
  int item_count;
  uint64_t ret;
  struct type_gen_alloc_struct_t *next;
} type_gen_alloc_t;

void mallocless_python_hook_PyMem_RawMalloc(uint64_t size, void *ptr);
void mallocless_python_hook_PyMem_RawCalloc(uint64_t count, uint64_t size, void *ptr);
void mallocless_python_hook_PyMem_RawRealloc(void *old_ptr, uint64_t size, void *new_ptr);
void mallocless_python_hook_PyMem_RawFree(void *ptr);

void mallocless_python_hook_PyObject_Malloc(uint64_t size, void *ptr);
void mallocless_python_hook_PyObject_Calloc(uint64_t count, uint64_t size, void *ptr);
void mallocless_python_hook_PyObject_Realloc(void *old_ptr, uint64_t size, void *new_ptr);
void mallocless_python_hook_PyObject_Free(void *ptr);

void malloc_python_hook_Python_start();
void malloc_python_hook_Python_end();

void malloc_python_hook_type_gen_alloc(
    const char *name, int base_size, int element_size, int total_size, int item_count, uint64_t ret);

#ifdef __cplusplus
}
#endif

#endif
