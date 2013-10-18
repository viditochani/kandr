#include<stdio.h>

#define TABSTOP 2

int main() { 
  int i, c, sc;

  sc=0;
  while ((c=getchar()) != EOF) {
    if (sc >= TABSTOP) {
      printf("\t");
      sc = 0;
    }

    if (c==' ') {
      sc++;
    } else if (sc<TABSTOP) {
      for (i=0; i<sc; i++)
        printf(" ");
      printf("%c", c);
      sc = 0;
    } else {
      printf("%c", c);
    }
  }
  return 0;
}
