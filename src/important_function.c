#include <stdio.h>
#include <math.h>

float ImportantFunction(float x);

int main(){
  float x;
  scanf("%f", &x);
  if (x == 0)
    printf("n/d");
  else
    printf("%.1f", ImportantFunction(x));
  return 0;
}

float ImportantFunction(float x){
  float y;
  y = 7e-3 * pow(x, 4) + ((22.8 * pow(x, 1.0/3.0) - 1e3) * x + 3) / (pow(x, 2) / 2.0) - x * pow((10 + x), (2.0 / x)) - 1.01;
  return y;
}
