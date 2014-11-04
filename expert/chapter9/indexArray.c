#include <stdio.h>

void fun(int *arr)
{
  int i = 1;
  //printf("print %d\n",*arr);  //0
  //printf("print %d\n",*(arr+1));  //1
  for(;i <= 5; i++)
  {
    printf("str is %d\n",arr[i]);
    //printf("str is %d\n",*(arr + i)); //same
  }
}

/*
 * 使用数组从1开始
 */
int main()
{
  int array[6] = {0,1,2,3,4,5};
  fun(array);
  return 0;
}
