#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

int current_element = 0;
int total_element = 128;
char *dynamic;
jmp_buf buf;

void add_element(char c){
  if(current_element == total_element - 1){
    total_element = total_element * 2;
    char *tmp = realloc(dynamic,total_element);
    if(tmp == NULL){
      longjmp(buf,1);
    }else{
      dynamic = tmp;
    }
  }
  current_element++;
  dynamic[current_element] = c;
}
int main()
{
  dynamic = malloc(total_element);
  setjmp(buf);
  return 0;
}
