#include <stdio.h>

class Fruit {
  public: void peel(){
            printf("peel()\n");
          }
          void slice(){
            printf("slice %d\n",weight);
          }
          void juice(int count);
  private:int weight,calories_per_oz;
};

void Fruit::juice(int count){
  printf("juice %d\n",count);
  printf("this ptr = %p",this);
  this->weight--;
  weight--;
}

int main()
{
  Fruit melon;
  printf("address of melon = %x\n",&melon);
  printf("hello\n");
  melon.peel();
  melon.slice();
  melon.juice(10);
  return 0;
}
