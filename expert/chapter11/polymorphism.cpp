#include <stdio.h>

class Fruit {
  public: Fruit(int i,int j);  //构造函数
          Fruit(){;}
          ~Fruit(); //析构函数
          virtual void peel(){
            printf("peel() Fruit\n");
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

class Apple : public Fruit
{
  public:
      Apple();
      ~Apple(){}
      void make_candy_apple(float weight);
      void bob_for(int tub_id, int number_of_attempts);
      void peel(){
        printf("peel apple\n");
      }
};

Apple::Apple(){;}

int main()
{
  Apple apple;
  Fruit orange;
  Fruit *p;

  p = &apple;
  p -> peel();

  p = &orange;
  p -> peel();
  return 0;
}
