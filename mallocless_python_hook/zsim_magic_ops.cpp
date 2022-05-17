
#include "zsim_magic_ops.h"

#ifdef __cplusplus
extern "C" {
#endif

// General-purpose magic op interface
void zsim_magic_op(zsim_magic_op_t *op) {
  // Write op pointer into R10
  __asm__ __volatile__("mov %0, %%r10\n\t"
                     : /* no output */
                     : "a"(op)
                     : "%r10");
  // XCHG R10, R10
  __asm__ __volatile__ (".byte 0x4D, 0x87, 0xD2");
  return;
}

// Short hands that just call into the general interface

void zsim_magic_op_hello_world() {
  zsim_magic_op_t op;
  op.op = ZSIM_MAGIC_OP_HELLO_WORLD;
  zsim_magic_op(&op);
  return;
}

void zsim_magic_op_print_str(const char *s) {
  zsim_magic_op_t op;
  op.op = ZSIM_MAGIC_OP_PRINT_STR;
  op.arg = (void *)s;
  zsim_magic_op(&op);
  return;
}

void zsim_magic_op_start_sim() {
  zsim_magic_op_t op;
  op.op = ZSIM_MAGIC_OP_START_SIM;
  zsim_magic_op(&op);
  return;
}

void zsim_magic_op_end_sim() {
  zsim_magic_op_t op;
  op.op = ZSIM_MAGIC_OP_END_SIM;
  zsim_magic_op(&op);
  return;
}

void zsim_magic_op_pause_sim() {
  zsim_magic_op_t op;
  op.op = ZSIM_MAGIC_OP_PAUSE_SIM;
  zsim_magic_op(&op);
  return;
}

void zsim_magic_op_pause_sim_alloc(uint64_t alloc_size) {
  zsim_magic_op_t op;
  op.op = ZSIM_MAGIC_OP_PAUSE_SIM_ALLOC;
  op.alloc_size = alloc_size;
  zsim_magic_op(&op);
  return;
}

void zsim_magic_op_pause_sim_free(uint64_t free_addr) {
  zsim_magic_op_t op;
  op.op = ZSIM_MAGIC_OP_PAUSE_SIM_FREE;
  op.free_addr = free_addr;
  zsim_magic_op(&op);
  return;
}

void zsim_magic_op_pause_sim_memcpy(uint64_t dest, uint64_t src, uint64_t size) {
  zsim_magic_op_t op;
  op.op = ZSIM_MAGIC_OP_PAUSE_SIM_MEMCPY;
  op.memcpy_dest = dest;
  op.memcpy_src = src;
  op.memcpy_size = size;
  zsim_magic_op(&op);
  return;
}

void zsim_magic_op_pause_sim_mmap(uint64_t size, uint64_t prot, uint64_t flags) {
  zsim_magic_op_t op;
  op.op = ZSIM_MAGIC_OP_PAUSE_SIM_MMAP;
  op.mmap_size = size;
  op.mmap_prot = prot;
  op.mmap_flags = flags;
  zsim_magic_op(&op);
  return;
}

void zsim_magic_op_pause_sim_munmap(uint64_t size, uint64_t addr) {
  zsim_magic_op_t op;
  op.op = ZSIM_MAGIC_OP_PAUSE_SIM_MUNMAP;
  op.munmap_size = size;
  op.munmap_addr = addr;
  zsim_magic_op(&op);
  return;
}

void zsim_magic_op_resume_sim() {
  zsim_magic_op_t op;
  op.op = ZSIM_MAGIC_OP_RESUME_SIM;
  zsim_magic_op(&op);
  return;
}

void zsim_magic_op_malloc(int size, uint64_t ptr) {
  zsim_magic_op_t op;
  zsim_alloc_t alloc;
  alloc.size = size;
  alloc.ptr = ptr;
  op.arg = &alloc;
  op.op = ZSIM_MAGIC_OP_MALLOC;
  zsim_magic_op(&op);
  return;
}

void zsim_magic_op_calloc(int count, int size, uint64_t ptr) {
  zsim_magic_op_t op;
  zsim_alloc_t alloc;
  alloc.count = count;
  alloc.size = size;
  alloc.ptr = ptr;
  op.arg = &alloc;
  op.op = ZSIM_MAGIC_OP_CALLOC;
  zsim_magic_op(&op);
  return;
}

void zsim_magic_op_realloc(uint64_t old_ptr, int size, uint64_t new_ptr) {
  zsim_magic_op_t op;
  zsim_alloc_t alloc;
  alloc.old_ptr = old_ptr;
  alloc.size = size;
  alloc.new_ptr = new_ptr;
  op.arg = &alloc;
  op.op = ZSIM_MAGIC_OP_REALLOC;
  zsim_magic_op(&op);
  return;
}

void zsim_magic_op_free(uint64_t ptr) {
  zsim_magic_op_t op;
  zsim_alloc_t alloc;
  alloc.ptr = ptr;
  op.arg = &alloc;
  op.op = ZSIM_MAGIC_OP_FREE;
  zsim_magic_op(&op);
  return;
}

void zsim_magic_op_memcpy(uint64_t dest, uint64_t src, uint64_t size) {
  zsim_magic_op_t op;
  op.memcpy_dest = dest;
  op.memcpy_src = src;
  op.memcpy_size = size;
  op.op = ZSIM_MAGIC_OP_MEMCPY;
  zsim_magic_op(&op);
  return;
}

void zsim_magic_op_mmap(uint64_t size, uint64_t prot, uint64_t flags, uint64_t addr) {
  zsim_magic_op_t op;
  op.mmap_size = size;
  op.mmap_prot = prot;
  op.mmap_flags = flags;
  op.mmap_addr = addr;
  op.op = ZSIM_MAGIC_OP_MMAP;
  zsim_magic_op(&op);
  return;
}

void zsim_magic_op_munmap(uint64_t size, uint64_t addr) {
  zsim_magic_op_t op;
  op.munmap_size = size;
  op.munmap_addr = addr;
  op.op = ZSIM_MAGIC_OP_MUNMAP;
  zsim_magic_op(&op);
}

void zsim_magic_op_append_stat_snapshot() {
  zsim_magic_op_t op;
  op.op = ZSIM_MAGIC_OP_APPEND_STAT_SNAPSHOT;
  zsim_magic_op(&op);
  return;
}

#ifdef __cplusplus
}
#endif