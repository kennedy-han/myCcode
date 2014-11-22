/*
 * 只要对max宏不是嵌套调用，就可以正常工作
 */
#include <stdio.h>
#define max(a,b) \
  (max_temp1=(a),max_temp2=(b), \
   max_temp1>max_temp2?max_temp1:max_temp2)

static int max_temp1, max_temp2;
int main()
{
  int a = 3, b = 4;
  int c = max(a,b);
  printf("c is %d\n",c);
  return 0;
}
