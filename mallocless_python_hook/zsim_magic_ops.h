
// This file contains magic ops that can be called by the compiled binary to pass
// information to the simulator.

#include <stdint.h>

//* zsim - zsim related functions, called by application to communicate with the simulator

enum {
  ZSIM_MAGIC_OP_HELLO_WORLD,
  ZSIM_MAGIC_OP_PRINT_STR,
  ZSIM_START_SIM,
  ZSIM_MAGIC_OP_GET_ADDR_MAPPING,
  // Random number related
  ZSIM_MAGIC_OP_GET_RAND32,
  ZSIM_MAGIC_OP_GET_RAND64,
  // Memory allocation related instrumentation
  ZSIM_MAGIC_OP_MALLOC,
  ZSIM_MAGIC_OP_CALLOC,
  ZSIM_MAGIC_OP_REALLOC,
  ZSIM_MAGIC_OP_FREE,
};

// The struct that contains full information about the magic op
typedef struct {
  int op;
  union {
    void *arg;
    int rand_32;
    uint64_t rand_64;
  };
} zsim_magic_op_t;

// This struct is used to pass information from the application to the simulator
// The application allocates a struct like this, and passes the pointer to zSim using zsim_magic_op()
typedef struct {
  int type_id;        // Not used
  union {
    uint64_t ptr;     // malloc, calloc, and free uses this
    uint64_t new_ptr; // realloc uses this
  };
  int size;           // malloc, calloc, and realloc uses this
  int count;          // calloc uses this
  uint64_t old_ptr;   // realloc uses this
} zsim_alloc_t;

// General-purpose magic op interface
inline static void zsim_magic_op(zsim_magic_op_t *op) {
  // Write op pointer into R10
  __asm__ __volatile__("mov %0, %%r10\n\t"
                     : /* no output */
                     : "a"(op)
                     : "%r10");
  // XOR R10, R10
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
