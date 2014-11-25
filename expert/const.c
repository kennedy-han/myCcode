#include <stdio.h>

/*利用方法形参去掉const指针类型*/
int foo(int * tmp)
{
  *tmp = *tmp + 10;
  return 0;
}

int main()
{
  const int limit = 10;
  //const int * limitp = &limit;
  const int * limitp = &limit;
  foo(limitp);
  printf("limitp is = %d\n",*limitp);
  return 0;
}
