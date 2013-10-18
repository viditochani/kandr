#include<stdio.h>
#include<limits.h>

int countbits();
int rightrot(unsigned int x, int n);
int main() {

  int x = 14;
  printf("Before %d \n", x);
  x = rightrot(x, 3);
  printf("After %d \n", x);
  return 0;
}
int rightrot(unsigned int x, int n) {
  return ((x>>n) | (x<<(countbits()-n)));
}
int countbits() {
  int i = 0;
  unsigned int x = ~0;
  for (; x; i++) {
    x &= x-1;
  }
  return i;
}
