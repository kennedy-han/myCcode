#include <stdio.h>

foo (const char **p){}

int main(int argc,char **argv)
{
  foo(argv);
  return 0;
}
