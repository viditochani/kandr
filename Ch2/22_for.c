#include<stdio.h>
#define MAXWORD 100

int main() {
  int c;
  char s[MAXWORD];

  for (i=0; i<lim-1; i++) {
    c = getchar();
    if (c==EOF) 
      i = lim-1;
    else if (c=='\n') 
      i = lim-1;
    else 
      s[i] = c;
  }
  return 0;
}
