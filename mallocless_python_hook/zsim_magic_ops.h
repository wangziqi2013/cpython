
// This file contains magic ops that can be called by the compiled binary to pass
// information to the simulator.

#ifndef _ZSIM_MAGIC_OPS_H
#define _ZSIM_MAGIC_OPS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum {
  ZSIM_MAGIC_OP_HELLO_WORLD,
  ZSIM_MAGIC_OP_PRINT_STR,
  ZSIM_MAGIC_OP_START_SIM,         // Index 2
  ZSIM_MAGIC_OP_GET_ADDR_MAPPING,
  ZSIM_MAGIC_OP_ADDR_MAP_ALLOC,
  // Random number related
  ZSIM_MAGIC_OP_GET_RAND32,
  ZSIM_MAGIC_OP_GET_RAND64,
  // Memory allocation related instrumentation
  ZSIM_MAGIC_OP_MALLOC,           // Index 7
  ZSIM_MAGIC_OP_CALLOC,
  ZSIM_MAGIC_OP_REALLOC,
  ZSIM_MAGIC_OP_FREE,
  ZSIM_MAGIC_OP_MEMCPY,
  ZSIM_MAGIC_OP_MMAP,
  ZSIM_MAGIC_OP_MUNMAP,
  // Progress control
  ZSIM_MAGIC_OP_PAUSE_SIM,        // Index 14. Pause simulation after it has started
  ZSIM_MAGIC_OP_RESUME_SIM,       // Index 15. Resume simulation
  ZSIM_MAGIC_OP_PAUSE_SIM_ALLOC,  // Index 16. Allocation pause
  ZSIM_MAGIC_OP_PAUSE_SIM_FREE,   // Index 17. Free pause
  ZSIM_MAGIC_OP_PAUSE_SIM_MEMCPY, // Index 18. Memcpy pause
  ZSIM_MAGIC_OP_PAUSE_SIM_MMAP,   // Index 19. Mmap
  ZSIM_MAGIC_OP_PAUSE_SIM_MUNMAP, // Index 20. Munmap
  // Stat control
  ZSIM_MAGIC_OP_APPEND_STAT_SNAPSHOT,
  // End sim
  ZSIM_MAGIC_OP_END_SIM,          // Index 22. End simulation
};

// The struct that contains full information about the magic op
typedef struct {
  int op;
  union {
    void *arg;
    int rand_32;
    uint64_t rand_64;
    uint64_t free_addr;   // pause for free
    uint64_t alloc_size;  // pause for allocation
    struct {              // This is for memcpy
      uint64_t memcpy_dest;
      uint64_t memcpy_src;
      uint64_t memcpy_size;
    };
    struct {              // This is for mmap
      uint64_t mmap_size;
      uint64_t mmap_prot;
      uint64_t mmap_flags;
      uint64_t mmap_addr; // Return value of mmap
    };
    struct {              // This is for munmap
      uint64_t munmap_size;
      uint64_t munmap_addr;
    };
  };
} zsim_magic_op_t;

// This is used to request allocation on the 2D space, with op ZSIM_MAGIC_OP_ADDR_MAP_ALLOC
typedef struct {
  int type_id;
  uint64_t addr_1d;
  int size;
} main_addr_map_alloc_data_t;

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

// These must be defined as macros, because they need to be fully inlined into the source
// application
#define ZSIM_MAGIC_OP_PAUSE_ISSUE   __asm__ __volatile__ (".byte 0x4D, 0x87, 0xE4");
#define ZSIM_MAGIC_OP_RESUME_ISSUE  __asm__ __volatile__ (".byte 0x4D, 0x87, 0xED");

void zsim_magic_op(zsim_magic_op_t *op) __attribute__ ((noinline));
void zsim_magic_op_hello_world();
void zsim_magic_op_print_str(const char *s);
void zsim_magic_op_start_sim();
void zsim_magic_op_end_sim();
void zsim_magic_op_pause_sim();
void zsim_magic_op_pause_sim_alloc(uint64_t alloc_size);
void zsim_magic_op_pause_sim_free(uint64_t free_addr);
void zsim_magic_op_pause_sim_memcpy(uint64_t dest, uint64_t src, uint64_t size);
void zsim_magic_op_pause_sim_mmap(uint64_t size, uint64_t prot, uint64_t flags);
void zsim_magic_op_pause_sim_munmap(uint64_t size, uint64_t addr);
void zsim_magic_op_resume_sim();
void zsim_magic_op_malloc(int size, uint64_t ptr);
void zsim_magic_op_calloc(int count, int size, uint64_t ptr);
void zsim_magic_op_realloc(uint64_t old_ptr, int size, uint64_t new_ptr);
void zsim_magic_op_free(uint64_t ptr);
void zsim_magic_op_memcpy(uint64_t dest, uint64_t src, uint64_t size);
void zsim_magic_op_mmap(uint64_t size, uint64_t prot, uint64_t flags, uint64_t addr);
void zsim_magic_op_munmap(uint64_t size, uint64_t addr);

void zsim_magic_op_append_stat_snapshot();

#ifdef __cplusplus
}
#endif

#endif