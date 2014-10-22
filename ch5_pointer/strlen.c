#include <stdio.h>

int tstrlen(char *s);

int main()
{
  char *ptr = "ppppp";
  int n = tstrlen("asdf");
  printf("n = %d \n",n);
  n = tstrlen(ptr);
  printf("n = %d \n",n);
  return 0;
}

int tstrlen(char *s)
{
  int n;

  for(n = 0; *s != '\0'; s++){
    n++;
  }
  return n;
}
