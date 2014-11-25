#include <stdio.h>
#include <stdlib.h>

//paf是一个函数，它返回一个指向包含20个int元素的数组的指针
int (*paf())[20];

int (*paf())[20] {
  int (*pear)[20]; /*声明一个指向包含20个int元素的数组的指针*/
  pear = calloc(20,sizeof(int));
  //if(!pear) longjmp(erorr,1);
  return pear;
}

int main()
{
  int (*result)[20];
  result = paf(); //调用函数
  (*result)[3] = 12;  //访问结果数组
  return 0;
}
