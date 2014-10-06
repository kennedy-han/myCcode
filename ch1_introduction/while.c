#include <stdio.h>

main()
{
  float fahr,celsius;
  int lower,upper,step;

  lower = 0;  //温度表的下限
  upper = 300;  //温度表的上线
  step = 20;  //步长

  printf("Celsius  Fahr\n");
  celsius = lower;
  while(celsius <= upper){
    fahr = (9.0 * celsius) / 5.0 + 32.0;
    printf("%3.0f\t%6.1f\n",celsius,fahr);
    celsius = celsius + step;
  }
}
