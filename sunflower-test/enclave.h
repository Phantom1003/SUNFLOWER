#ifndef ENCLAVE_H
#define ENCLAVE_H

#define TSYS_ADD_FUNC      0x1
#define TSYS_ADD_DATA      0x2
#define TSYS_DELETE_TAG    0x3
#define TSYS_CALCULATE_SHA 0x4

#include <stdlib.h>

typedef struct
{
  int cause;
  void * baseAddr;
  void * boundAddr;
} tsysframe_t;

void (*tsyscall)(tsysframe_t *ts);


static void add_enclave(void * start, void * end)       /* add tu tag to memory between start and end */
{
    tsyscall = (void *)0x80000000;        /* trust syscall handler */
    tsysframe_t *ts=(tsysframe_t *)malloc(sizeof(tsysframe_t));
    ts->cause=TSYS_ADD_FUNC;
    ts->baseAddr=start;
    ts->boundAddr=end;
    (* tsyscall)(ts);

}

static void add_data(void * start, int length)       /* add tu tag to memory between start and end */
{
    tsyscall = (void *)0x80000000;        /* trust syscall handler */
    tsysframe_t *ts=(tsysframe_t *)malloc(sizeof(tsysframe_t));
    ts->cause=TSYS_ADD_DATA;
    ts->baseAddr=start;
    ts->boundAddr=(void *)((long)start + length);
    (* tsyscall)(ts);
}

// 1cbe0


/* static void add_secure_entry(long addr)         // add tc tag to memory at addr 
{
    tsysframe_t *ts=(tsysframe_t *)malloc(sizeof(tsysframe_t));
    ts->cause=TSYS_ADD_ENTRY;
    ts->baseAddr=addr;
    ts->boundAddr=NULL;
    tsyscall(ts);
} */

static void delete_enclave(void * start, void * end)    /* change to n tag between start and end */
{
    tsyscall = (void *)0x80000000;        /* trust syscall handler */
    tsysframe_t *ts=(tsysframe_t *)malloc(sizeof(tsysframe_t));
    ts->cause=TSYS_DELETE_TAG;
    ts->baseAddr=start;
    ts->boundAddr=end;
    (* tsyscall)(ts);
}

static void init_enclave(void * start, void * end)  /* calculate SHA */
{
    tsyscall = (void *)0x80000000;        /* trust syscall handler */
    tsysframe_t *ts=(tsysframe_t *)malloc(sizeof(tsysframe_t));
    ts->cause=TSYS_CALCULATE_SHA;
    ts->baseAddr=start;
    ts->boundAddr=end;
    (* tsyscall)(ts);
}

#endif
