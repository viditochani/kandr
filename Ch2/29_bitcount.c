#include<stdio.h>

int bitcount(int n);
int main() {
  int x=43;
  printf("%d\n", bitcount(x));
  return 0;
}
int bitcount(int n) {
  int i=0;
  while(n) {
    n &= n-1;
    i++;
  }
  return i;
}
