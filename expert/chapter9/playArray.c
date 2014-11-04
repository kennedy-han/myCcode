#include <stdio.h>

void fun1(char ca[10])
{
  printf("ca is %#x \n ",&ca);
  printf("ca[0] is %#x \n ",&(ca[0]));
  printf("ca[1] is %#x \n ",&(ca[1]));
  printf("++ca is %#x \n ",++ca);
}

void fun2(char *pa)
{
  printf("sizeof pa is %ld\n",sizeof(pa));
  printf("sizeof &(pa[0]) is %ld\n",sizeof(&(pa[0])));
  printf("sizeof &(pa[1]) is %ld\n",sizeof(&(pa[1])));
  //printf("&pa is %p\n",&pa);
  //printf("&(pa[0]) is %s\n",&(pa[0]));
  //printf("&(pa[1]) is %s\n",&(pa[1]));
  //printf("++pa is %s\n",++pa);
  printf("&pa is %#x\n",&pa);
  printf("&(pa[0]) is %#x\n",&(pa[0]));
  printf("&(pa[1]) is %#x\n",&(pa[1]));
  printf("++pa is %#x\n",++pa);
}

char ga[] = "abcdefghijklm";
int main()
{
  //fun1("abcdef");
  //fun2("abcdef");

  fun1(ga);
  fun2(ga);

  printf("&pa is %#x\n",&ga);
  printf("&(pa[0]) is %#x\n",&(ga[0]));
  printf("&(pa[1]) is %#x\n",&(ga[1]));
  return 0;
}
