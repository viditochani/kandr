#include<stdio.h>

int invert(unsigned int x, int p, int n);
int main() {

  int x = 12;
  printf("Before %d \n", x);
  x= invert(x, 3, 2);
  printf("After %d \n", x);
  return 0;
}

int invert(unsigned int x, int p, int n) {
  /* 
   * Creates a binary mask of form 11..100...00000
   *                                    ^
   *                                    p
   */
  unsigned int a = ~0 << p;
  /* 
   * Creates a binary mask of form 00..0000..01111
   *                                    ^    ^
   *                                    p   p-n
   */
  unsigned int b = ~(~0 << (p-n));
  /* 
   * Creates a binary mask of form 11..1000..01111
   *                                    ^    ^
   *                                    p   p-n
   */
  unsigned int mask = (a|b);

  return ((x&mask) | (~x&~mask));
}



