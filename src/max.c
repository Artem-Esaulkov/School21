#include <stdio.h>

int MaximalNumber(int a, int b);

int main(){
  float a, b;
  scanf("%f %f", &a, &b);
  if ((int)(a) != a || (int)(b) != b){
    printf("n/a");
  }
  else {
    printf("%d", MaximalNumber((int)a, (int)b));
  }
  return 0;
}

int MaximalNumber(int a, int b){
  int max = a;
  if (b > a)
    max = b;
  return max;
}
