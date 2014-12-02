#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void error(char *format, ...)
{
  va_list ap;
  va_start(ap,format);
  fprintf(stderr,"error: ");
  vfprintf(stderr,format,ap);
  va_end(ap);
  fprintf(stderr,"\n");
  exit(0);
}

int main()
{
  error("err: %s %s","a","b");
  return 0;
}
