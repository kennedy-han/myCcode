#include <stdio.h>

/*
 *4.从终端（键盘）将5个整数输入到数组a中，然后将a逆序复制到数组b中，并输出b中各元素的值。
 */
int main()
{
  int a[5];
  int b[5];
  int i,j;
  for(i = 0; i < 5; i++){
    scanf("%d",&a[i]);
  }

  for(i = 0, j = 4; i < 5; j--,i++){
    b[j] = a[i];
  }

  for(i = 0; i < 5; i++){
    printf("b is %d\n",b[i]);
  }
  return 0;
}
