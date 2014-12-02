#include <stdio.h>
#include <varargs.h>

/*
 * mac下va_dcl编译不通过
 */
void error (va_alist) va_dcl
{
  va_list ap;
  char *format;

  va_start(ap);
  format = va_arg(ap,char *);
  fprintf(stderr,format,ap);
  va_end(ap);
  fprintf(stderr,"\n");
  exit(1);
}

int main()
{
  error("hi %s %s","a","b");
}


