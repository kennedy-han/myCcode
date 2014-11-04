#include <stdio.h>

int main()
{
  int num = 0;
  float *p = &num;

  printf("num is %d\n",num);
  printf("p is %f\n",*p);

  *p = 9.0;

  printf("num is %d\n",num);
  printf("p is %f\n",*p);
  return 0;
}
