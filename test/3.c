#include <stdio.h>

/*
 * 3.从终端（键盘）读入20个数据到数组中，统计其中正数的个数，并计算这些正数之和。
 */
int main()
{
  int array[20];
  int i,sum,count;
  for(i = 0; i < 20; i++){
    scanf("%d",&array[i]);
  }

  sum = 0;  //总和
  count = 0;  //正数的个数
  for(i = 0; i < 20; i++){
    if(array[i] > 0){
      sum += array[i];
      count ++;
    }
  }
  printf("count = %d\n",count);
  printf("sum = %d\n",sum);
  return 0;
}
