#ifndef TSYSCALL_H
#define TSYSCALL_H

#include <stdint.h>
#include "pk.h"

#define TSYS_ADD_FUNC      0x1
#define TSYS_ADD_DATA      0x2
#define TSYS_DELETE_TAG    0x3
#define TSYS_CALCULATE_SHA 0x4

typedef uint64_t uword_t;

#define TSYSCALL __attribute__((section(".tsyscall")))

typedef struct
{
  int cause;
  long baseAddr;
  long boundAddr;
} tsysframe_t;


static void TSYSCALL add_func(tsysframe_t *ts)
{
  for(long i=ts->baseAddr; i<ts->boundAddr; i+=4) {
    //volatile register uword_t at_temp = 0;
    //volatile register void* at_addr = (void*)(i);
    //asm volatile ("ldct n, %0, (%1)\n"
    //             "sdct n, ut, %0, (%1)\n"
    //              : "+r"(at_temp) : "r"(at_addr) : "memory");
    asm volatile("stag %[x], 0(%[y])\n" : : [x]"r"(2), [y]"r"(i));
  }
    asm volatile("stag %[x], 0(%[y])\n" : : [x]"r"(1), [y]"r"(ts->baseAddr));
  // add_entry(ts);
}

static void TSYSCALL add_data(tsysframe_t *ts)
{
  for(long i=ts->baseAddr; i<ts->boundAddr; i+=4) {
    //volatile register uword_t at_temp = 0;
    //volatile register void* at_addr = (void*)(i);
    //asm volatile ("ldct n, %0, (%1)\n"
    //             "sdct n, ut, %0, (%1)\n"
    //              : "+r"(at_temp) : "r"(at_addr) : "memory");
    asm volatile("stag %[x], 0(%[y])\n" : : [x]"r"(2), [y]"r"(i));
  }
}



static void TSYSCALL delete_tag(tsysframe_t *ts)
{
 /* volatile register uword_t cst_temp = 0;
  volatile register void* cst_addr = (void*)(ts->baseAddr);
  asm volatile ("ldct c, %0, (%1)\n"
                "sdct c, n, %0, (%1)\n"
                : "+r"(cst_temp) : "r"(cst_addr) : "memory");
  for(long i=ts->baseAddr+8; i<=ts->boundAddr; i++) {
    cst_addr = (void*)(i);
    asm volatile ("ldct ut, %0, (%1)\n"
                  "sdct ut, n, %0, (%1)\n"
                  : "+r"(cst_temp) : "r"(cst_addr) : "memory");
  }*/
  for(long i=ts->baseAddr; i<ts->boundAddr; i++) {
    asm volatile("stag %[x], 0(%[y])\n" : : [x]"r"(0), [y]"r"(i));
  }
}

static void TSYSCALL calculate_sha(tsysframe_t *ts)
{
  // TODO 
}

static void TSYSCALL init_set_tag(long baseAddr, long boundAddr)
{
  printk("\033[1;33m[Boot] Load Trust Service between %p ~ %p\033[0m\n", baseAddr, boundAddr);
  for(long i=baseAddr; i<boundAddr; i++) {
    asm volatile("stag %[x], 0(%[y])\n" : : [x]"r"(3), [y]"r"(i));
  }
  asm volatile("stag %[x], 0(%[y])\n" : : [x]"r"(1), [y]"r"(baseAddr));
 
}

void __attribute__((section("trust_trap_entry"))) handle_trust_syscall(tsysframe_t *ts)
{
 // typedef void (*tsyscall_handler)(tsysframe_t *);
 // const static tsyscall_handler tsyscall_handlers[] = {
 //   [TSYS_ADD_TAG] = add_tag,
 //   [TSYS_ADD_ENTRY] = add_entry,
 //   [TSYS_DELETE_TAG] = delete_tag,
 //   [TSYS_CALCULATE_SHA] = calculate_sha,
 // };
 //   tsyscall_handlers[ts->cause](ts);
    switch (ts->cause){
      case TSYS_ADD_FUNC: add_func(ts); break;
      case TSYS_ADD_DATA: add_data(ts); break;
      case TSYS_DELETE_TAG: delete_tag(ts); break;
      case TSYS_CALCULATE_SHA: break;

  }
}

#endif
