#include <stdio.h>

int main()
{
  int ch;
  int flag;   //记录花括号数量

  flag = 0;

  while( (ch = getchar()) != EOF){
    if(ch == '{'){
      flag++;
    }

    if(ch == '}'){
      if(flag == 0){  //如果还没有检测到第一个{
        printf("Extra closing brace!\n");
        break;
      }else{
        flag--;
      }
    }
  }
  if(flag > 0){
    printf("%d unmatched opening brace(s)!\n",flag);
  }
  return 0;
}
