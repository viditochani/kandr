#include<stdio.h>

#define IN 1
#define OUT 0

int main() {
  int c, state;

  state = OUT;
  while ((c=getchar()) != EOF) {
    if (state == OUT) 
      printf("%c", c);
    if (c==' ') 
      state = IN;
    else if (state == IN) {
      state = OUT;
      printf("%c", c);
    }
  }
  return 0;
}
