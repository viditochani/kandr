#include<stdio.h> 

#define IN 1
#define OUT 0
#define MAXWORDLENGTH 100

int main() {
  int word_length[MAXWORDLENGTH];
  int i, c, nw, wl, state;

  state = OUT;   
  nw = wl = 0;
  for (i=0; i<MAXWORDLENGTH; i++) 
    word_length[i]=0;

  while ((c=getchar()) != EOF) {
    if (c==' ' || c=='\t' || c=='\n') {
      state = OUT;
    } else if (state==OUT) {
      nw++;
      if(wl) word_length[wl]++;

      wl=1;
      state = IN;
    } else if (state==IN) {
      wl++;
    }
  }
  for (i=0; i<MAXWORDLENGTH; i++) {
    if (word_length[i] > 0) {
      printf("%3d  ", i);
      for (c=0; c<word_length[i]; c++)
        printf("|");
      printf("\n");
    }
  }
  return 0;
}

