#include<stdio.h>

#define TRUE 1
#define FALSE 0

int main() {
  int c, empty, word;
  int i, s[2];

  empty=TRUE;
  while ((c=getchar())!=EOF) {
    if (c==' '||c=='\t') {
      word=FALSE;
      s[c%2]++;
    } else if (c=='\n') {
      s[0]=s[1]=0;
      if (!empty) printf("\n");
      empty=TRUE;
    } else {
      empty=FALSE;
      word=TRUE;

      for(i=0; i<s[' '%2]; i++) printf(" ");
      for(i=0; i<s['\t'%2]; i++) printf("\t");
      s[0]=s[1]=0;

      printf("%c", c);
    }
  }
  return 0;
}
      




