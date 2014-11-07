#include <stdio.h>

class Fruit {
  public: Fruit(int i,int j);  //构造函数
          ~Fruit(); //析构函数
          void peel(){
            printf("peel()\n");
          }
          void slice(){
            printf("slice %d\n",weight);
          }
          void juice(int count);
  private:int weight,calories_per_oz;
};

//构造函数体
Fruit::Fruit(int i,int j){
  weight = i;
  calories_per_oz = j;
  printf("construction Fruit:weight = %d,calor= %d\n",i,j);
}

//析构函数体
Fruit::~Fruit(){
  printf("destructor Fruit\n");
}

void test(){
  Fruit melon(2,3);
  Fruit banana(12,8);
}

int main()
{
  test();
  return 0;
}
