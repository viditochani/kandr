#include<stdio.h>

int setbits(unsigned int x, int p, int n, unsigned int y);
int main() {
  int x = 28;
  int y = 5;

  printf("Before x:%d and y:%d\n", x, y);
  x=setbits(x, 4, 2, y);
  printf("After x:%d and y:%d\n", x, y);
  return 0;
}
int setbits(unsigned int x, int p, int n, unsigned int y) {
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


  /* 
   * Masks out all bits except last n bits and then
   * shift them by p-n, resulting in 000XXX..X000
   *                                    ^    ^
   *                                    p   p-n
   */
  unsigned int c = (y & ~(~0<<n)) << (p-n);

  return ((x&mask) | c);
}
