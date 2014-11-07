#include <stdio.h>

class Fruit{
  public: void peel();
          int operator+(Fruit &f);  //重载+操作符
  private:int weight,calories_per_oz;
};

int Fruit::operator+(Fruit &f){
  printf("calling fruit addition\n");
  return weight + f.weight;
}

int main()
{
  Fruit apple;
  Fruit orange;
  int ounces = apple + orange;
  return 0;
}
