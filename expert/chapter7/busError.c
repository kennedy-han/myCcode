#include <stdio.h>

union {
  char a[10];
  int i;
} u;

int main()
{
  int *p = (int *) &(u.a[1]);
  *p = 17;
  printf("p is %d\n",*p);
  return 0;
}
