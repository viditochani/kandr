#include<stdio.h> 

#define CHARS 256

int main() {
  int char_count[CHARS];
  int i, c;

  for (i=0; i<CHARS; i++) 
    char_count[i]=0;

  while ((c=getchar()) != EOF) {
    if (c==' ' || c=='\t' || c=='\n') {
    } else {
      char_count[c]++;
    }
  }
  for (i=0; i<CHARS; i++) {
    if (char_count[i] > 0) {
      printf("%c ", i);
      for (c=0; c<char_count[i]; c++)
        printf("|");
      printf("\n");
    }
  }
  return 0;
}

