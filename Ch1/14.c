#include<stdio.h>

int main() {
  float celsius, fahr;
  int lower, upper, step;
  
  lower = 6;
  upper = 150;
  step = 10;
  
  celsius = lower;
  printf("Celsius to Farenheit table\n");
  while (celsius <= upper) {
    fahr = (9.0/5.0) * (celsius+32.0);
    printf("%3.0f %6.1f\n", celsius, fahr);
    celsius += step;
  }
  return 0;
}


