
#ifndef _MALLOCLESS_PYTHON_HOOK_H
#define _MALLOCLESS_PYTHON_HOOK_H

#include <stdint.h>
#include "zsim_magic_ops.h"

#ifdef __cplusplus
extern "C" {
#endif

void mallocless_python_hook_PyMem_RawMalloc(uint64_t size, void *ptr);
void mallocless_python_hook_PyMem_RawCalloc(uint64_t count, uint64_t size, void *ptr);
void mallocless_python_hook_PyMem_RawRealloc(void *old_ptr, uint64_t size, void *new_ptr);
void mallocless_python_hook_PyMem_RawFree(void *ptr);

void mallocless_python_hook_PyObject_Malloc(uint64_t size, void *ptr);
void mallocless_python_hook_PyObject_Calloc(uint64_t count, uint64_t size, void *ptr);
void mallocless_python_hook_PyObject_Realloc(void *old_ptr, uint64_t size, void *new_ptr);
void mallocless_python_hook_PyObject_Free(void *ptr);
void mallocless_python_hook_Mmap(uint64_t size, uint64_t prot, uint64_t flags, void *ptr);
void mallocless_python_hook_Munmap(uint64_t size, void *ptr);

void mallocless_python_hook_memcpy(void *dest, void *src, uint64_t size);

#ifdef __cplusplus
}
#endif

#endif