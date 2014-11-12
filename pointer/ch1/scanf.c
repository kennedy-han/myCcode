#include <stdio.h>

int main()
{
  int quantity,price;
  char department[10];
  scanf("%d\n%d\n%s",&quantity,&price,department);
  printf("q = %d\n p = %d\n d = %s\n",quantity,price,department);
  return 0;
}
