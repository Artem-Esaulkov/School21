#include <stdio.h>

int sum(int a, int b);
int dif(int a, int b);
int mul(int a, int b);
int quo(int a, int b);

int main()
{
  int a, b;
  scanf("%d %d", &a, &b);
  if (b == 0){
    printf("%d %d %d n/a", sum(a, b), dif(a, b), mul(a, b));
  }
  else
    printf("%d %d %d %d", sum(a, b), dif(a, b), mul(a, b), quo(a, b));
  return 0;
}

int sum(int a, int b){
  return a + b;
}

int dif(int a, int b){
  return a - b;
}

int mul(int a, int b){
  return a * b;
}

int quo(int a, int b){
  return a / b;
}
