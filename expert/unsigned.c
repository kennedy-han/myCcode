#include <stdio.h>

int main()
{
  int array[] = {1,2,3,4,5,6,7,8,9};
  int d = -1,x;
  unsigned int total = sizeof(array);
  printf("%d\n",x);
  printf("%d\n",d);
  if( d <= total - 2){
    printf("less\n");
  }else{
    printf("great\n");
  }
  return 0;
}
