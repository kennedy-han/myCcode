#include <stdio.h>

#define IN 1 /*在单词内*/
#define OUT 0 /*在单词外*/

/*每行一个单词的形式，打印输入*/
main()
{
  int c,state;

  state = OUT;
  while((c = getchar()) != EOF){
    if(c == ' ' || c == '\n' || c == '\t'){
      if(state == IN){
        state = OUT;  /*finish the word*/
        putchar('\n');
      }
    }else if(state == OUT){
      state = IN; /*beginning of word*/
      putchar(c);
    }else{
      putchar(c); /*inside a word*/
    }
  }

}
