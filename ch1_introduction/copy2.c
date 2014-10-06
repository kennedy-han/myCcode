#include <stdio.h>

/*将输入复制到输出*/
main()
{
  int c;
  c = getchar();
  printf("EOF is %d\n",EOF);
  while(c != EOF){
    printf("%d\n",c);
    putchar(c);
    c = getchar();
  }
}
