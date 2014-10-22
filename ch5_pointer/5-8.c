#include <stdio.h>

int day_of_year(int year,int month,int day);
void month_day(int year,int yearday,int *pmonth,int *pday);

static char daytab[2][13] = {
  {0,31,28,31,30,31,30,31,31,30,31,30,31},
  {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int main()
{
  printf("hi");
  int *pmonth,*pday;
  day_of_year(2014,2,1);
  month_day(2014,3,pmonth,pday);
  printf("the month is %d\t and day is %d\n",*pmonth,*pday);
  return 0;
}

/*将某月某日的日期表示形式转换为某年中第几天的表示形式*/
int day_of_year(int year,int month,int day)
{
  int i,leap;

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  //if(month < 1 || month > 12){
  //  return -1;
  //}
  //if(day < 1 || day > daytab[leap][month]){
  //  return -1;
  //}
  for(i = 1; i < month; i++){
    day += daytab[leap][i];
  }
  return day;
}

/*将某年中第几天的日期转换为某月某日的表现形式*/
void month_day(int year,int yearday,int *pmonth,int *pday)
{
  int i,leap;

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  for(i = 1; yearday > daytab[leap][i]; i++){
    yearday -= daytab[leap][i];
  }
  //if( i > 12 && yearday > daytab[leap][12]){
  //  *pmonth = -1;
  //  *pday = yearday;
  //}else{
    *pmonth = i;
    *pday = yearday;
  //}
}

