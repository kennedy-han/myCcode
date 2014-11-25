#include <stdio.h>
#include <time.h>

int main()
{
  //printf("%ld\n",sizeof(long));   //8 bytes
  time_t biggest = 0x7FFFFFFF;

  printf("biggest = %s \n",ctime(&biggest));
  long seconds = time((time_t*)NULL);
  printf("now = %ld \n",seconds);
  return 0;
}
