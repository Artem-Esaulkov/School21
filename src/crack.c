#include <stdio.h>

int main(){
  float x, y;
  if (scanf("%f %f", &x, &y) != 2){
    printf("n/a");
  }
  else{
    x * x + y * y < 25 ? printf("GOTCHA") : printf("MISS");
  }
  return 0;
}
