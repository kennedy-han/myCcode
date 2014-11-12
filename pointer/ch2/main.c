#include <stdio.h>
#include "increment.h"
#include "negate.h"

int main()
{
  int a = 10;
  int b = 0;
  int c = -10;

  int returnA = increment(a);
  int returnB = increment(b);
  int returnC = increment(c);

  printf("a is %d\nb is %d\nc is %d\n",returnA,returnB,returnC);

  int na = negate(a);
  int nb = negate(b);
  int nc = negate(c);

  printf("a is %d\nb is %d\nc is %d\n",na,nb,nc);
  return 0;
}
