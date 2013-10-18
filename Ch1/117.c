
#include<stdio.h>
#define MAXLEN 1000

// stdio.h has getline
int getline2(char line[], int maxline);

int main() {
  int len;
  char line[MAXLEN];

  while((len = getline2(line, MAXLEN)) > 0) 
    if (len > 80) {
      printf("%s", line);
    }
  return 0;
}
int getline2(char line[], int lim) {
  int c, i;

  for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++) 
    line[i] = c;
  if (c == '\n')
    line[i++] = c;
  line[i] = '\0';
  return i;
}




    


  

