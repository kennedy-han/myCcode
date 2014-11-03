#include <stdio.h>
#include <signal.h>

void handler(int s)
{
  if (s == SIGBUS ) printf(" not got a bus error signal\n");
  if (s == SIGSEGV ) printf(" not got a segmentation violation signal\n");
  if (s == SIGILL ) printf(" not got an illegal instruction signal\n");
  exit(1);
}

main()
{
  int *p = NULL;
  signal(SIGBUS,handler);
  signal(SIGSEGV,handler);
  signal(SIGILL,handler);
  *p = 0;
}
