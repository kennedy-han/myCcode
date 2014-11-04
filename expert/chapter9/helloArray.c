#include <stdio.h>

int main()
{
  int apricot[2][3][5];

  int (*r)[5] = apricot[0];
  int *t = apricot[0][0];

  printf("r is %x\n",r);
  printf("t is %x\n",t);
  r++;
  t++;

  printf("r is %x\n",r);
  printf("t is %x\n",t);
  return 0;
}
