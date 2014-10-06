#include <stdio.h>

void reverse(char str[]);

int main()
{

  return 0;
}

void reverse(char str[])
{
  char tmp;
  int i,j;

  i = 0;
  while(str[i] != '\0'){
    ++i;
  }
  --i; //除去\0
  if(str[i] == '\n'){
    --i;
  }
  j = 0;
  while(j < i){
    tmp = str[j];
    str[j] = str[i];
    str[i] = tmp;
    --i;
    ++j;
  }
}
