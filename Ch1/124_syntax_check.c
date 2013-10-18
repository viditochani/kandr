#include<stdio.h>

#define IN 0
#define OUT 1
int main() {
  int i, j, c, state;
  i = j = 0;
  state = OUT;
  while ((c=getchar()) != EOF) {
    if (c=='(' && state==OUT) 
      i++;
    else if (c==')' && state==OUT)
      i--;
    else if (c=='{' && state==OUT)
      j++;
    else if (c=='}' && state==OUT)
      j--;
    else if ((c=='\'' || c=='"') && state==OUT)
      state=IN;
    else if ((c=='\'' || c=='"') && state==IN)
      state=OUT;

    if (i<0 || j<0) 
      break;
  }
  if (i<0 || i>0 || j>0 || j<0) 
    printf("invalid\n");
  else
    printf("valid\n");
}
