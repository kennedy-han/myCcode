#include <stdio.h>

void changeA(int *tmp)
{
  printf("before int is %d\n",*tmp);
  *tmp = 5;
  printf("after int is %d\n",*tmp);
}

int main()
{
  int a = 1;
  int *p = &a;
  changeA(p);
  printf("out int is %d\n",*p);
  return 0;
}
