
#include "mallocless_python_hook.h"

#ifdef __cplusplus
extern "C" {
#endif

void mallocless_python_hook_PyMem_RawMalloc(uint64_t size, void *ptr) {
  (void)size; (void)ptr;
  return;
}

void mallocless_python_hook_PyMem_RawCalloc(uint64_t count, uint64_t size, void *ptr) {
  (void)count; (void)size; (void)ptr;
  return;
}

void mallocless_python_hook_PyMem_RawRealloc(void *old_ptr, uint64_t size, void *new_ptr) {
  (void)old_ptr; (void)size; (void)new_ptr;
  return;
}

void mallocless_python_hook_PyMem_RawFree(void *ptr) {
  (void)ptr;
  return;
}

void mallocless_python_hook_PyObject_Malloc(uint64_t size, void *ptr) {
  (void)size; (void)ptr;
  return;
}

void mallocless_python_hook_PyObject_Calloc(uint64_t count, uint64_t size, void *ptr) {
  (void)count; (void)size; (void)ptr;
  return;
}

void mallocless_python_hook_PyObject_Realloc(void *old_ptr, uint64_t size, void *new_ptr) {
  (void)old_ptr; (void)size; (void)new_ptr;
  return;
}

void mallocless_python_hook_PyObject_Free(void *ptr) {
  (void)ptr;
  return;
}

#ifdef __cplusplus
}
#endif