#include <stdio.h>

int main()
{
  int ch;
  char checksum;

  checksum = 0;

  while( (ch = getchar()) != EOF){
    putchar(ch);
    checksum += ch;
    if( ch == '\n' ){
      printf("\t checksum = %d\n",checksum);
      checksum = 0;
    }
  }
  return 0;
}
