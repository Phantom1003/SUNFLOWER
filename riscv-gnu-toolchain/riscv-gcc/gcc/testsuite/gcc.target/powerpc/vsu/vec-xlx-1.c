/* { dg-do compile { target { powerpc*-*-* } } } */
/* { dg-skip-if "do not override -mcpu" { powerpc*-*-* } { "-mcpu=*" } { "-mcpu=power9" } } */
/* { dg-require-effective-target powerpc_p9vector_ok } */
/* { dg-options "-mcpu=power9" } */

#include <stddef.h>
#include <altivec.h>

unsigned char
fetch_data (unsigned int offset, vector unsigned char *datap)
{
  vector unsigned char data = *datap;

  return vec_xlx (offset, data);
}

/* { dg-final { scan-assembler "vextublx" } } */