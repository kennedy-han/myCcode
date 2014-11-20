#include <stdio.h>

int * binary_search(int *array, int value, int size)
{
  int low = 0;
  int high = size;
  while(low < high){
    int mid = (low + high) >> 1;
    if( value == array[mid]){
      return &array[mid];
    }else if(value > array[mid]){
      low = mid + 1;
    }else if(value < array[mid]){
      high = mid - 1;
    }
  }
  return NULL;
}

int main()
{
  int array[] = {1,2,3,4,5,6,7,8,9,10};
  int *res = binary_search(array, 11, 10);
  if(res == NULL){
    printf("not found!\n");
  }else{
    printf("res is %d\n",*res);
  }
  return 0;
}
