
#ifndef _MALLOCLESS_PYTHON_HOOK_H
#define _MALLOCLESS_PYTHON_HOOK_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zsim_magic_ops.h"

#ifdef __cplusplus
extern "C" {
#endif

// This var indicates the nest level of allocations 
// We use this to detect recursive calls (which will be ignored, because we only care the top-level
// allocation call).
extern int alloc_nest_level;

void malloc_python_hook_enter_alloc();
void malloc_python_hook_leave_alloc();

void malloc_python_hook_pyalloc_stat_print();
void malloc_python_hook_pyalloc_add(int type, uint64_t arg1, uint64_t arg2, uint64_t ret);

void mallocless_python_hook_RawMalloc(uint64_t size, void *ptr);
void mallocless_python_hook_RawCalloc(uint64_t count, uint64_t size, void *ptr);
void mallocless_python_hook_RawRealloc(void *old_ptr, uint64_t size, void *new_ptr);
void mallocless_python_hook_RawFree(void *ptr);

void mallocless_python_hook_PyMem_Malloc(uint64_t size, void *ptr);
void mallocless_python_hook_PyMem_Calloc(uint64_t count, uint64_t size, void *ptr);
void mallocless_python_hook_PyMem_Realloc(void *old_ptr, uint64_t size, void *new_ptr);
void mallocless_python_hook_PyMem_Free(void *ptr);

void mallocless_python_hook_PyObject_Malloc(uint64_t size, void *ptr);
void mallocless_python_hook_PyObject_Calloc(uint64_t count, uint64_t size, void *ptr);
void mallocless_python_hook_PyObject_Realloc(void *old_ptr, uint64_t size, void *new_ptr);
void mallocless_python_hook_PyObject_Free(void *ptr);

void mallocless_python_hook_mmap(uint64_t size, void *ptr);
void mallocless_python_hook_munmap(uint64_t size, void *ptr);

void malloc_python_hook_Python_start();
void malloc_python_hook_Python_end();

void malloc_python_hook_type_gen_stat_print();
void malloc_python_hook_type_gen_alloc(
    const char *name, int base_size, int element_size, int total_size, int item_count, uint64_t ret);

#ifdef __cplusplus
}
#endif

#endif
