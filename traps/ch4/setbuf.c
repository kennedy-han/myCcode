#include <stdio.h>

int main()
{
  int c;

  //static char buf[BUFSIZ];
  //setbuf(stdout,buf);

  char * malloc();
  setbuf(stdout,malloc(BUFSIZ));
  while(( c = getchar()) != EOF){
    putchar(c);
  }
  return 0;
}
