#include <stdio.h>

void my_function1(int fruit[2][3][5]){  ; }
void my_function2(int fruit[][3][5]){  ; }
void my_function3(int (*fruit)[3][5]){  ; }

int main()
{
  int apricot[2][3][5];
  my_function1(apricot);
  my_function2(apricot);
  my_function3(apricot);

  int (*p)[3][5] = apricot;
  my_function1(p);
  my_function2(p);
  my_function3(p);

  int (*q)[2][3][5] = &apricot;
  my_function1(*q);
  my_function2(*q);
  my_function3(*q);

  return 0;
}
