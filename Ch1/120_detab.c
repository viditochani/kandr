#include<stdio.h>

#define TABSTOP 2
int main() {
  int i, c;
  while ((c=getchar()) != EOF) {
    if (c == '\t') {
      for (i=0; i<TABSTOP; i++) 
        printf(" ");
    } else {
      printf("%c", c);
    }
  }
  return 0;
}
