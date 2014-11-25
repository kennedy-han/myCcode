#include <stdio.h>
#include "testExtern.h"

int main()
{
  int tmp = foo();
  printf("tmp is %d\n",tmp);
  return 0;
}
