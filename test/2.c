#include <stdio.h>

int main()
{
  int num,count;
  int i;
  printf("type a num:\n");
  scanf("%d",&num);
  printf("you typed %d\n",num);

  count = 0;
  for(i = 0; i <= num; i++){
    count += i;
  }
  printf("sum %d\n",count);
  return 0;
}
