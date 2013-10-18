#include<stdio.h>
#define MAXLEN 1000

// stdio.h has getline
int getline2(char line[], int maxline);
void reverse(char s[]);

int main() {
  int c, len;
  char line[MAXLEN];

  while((len = getline2(line, MAXLEN)) > 0) {
    reverse(line);
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
void reverse(char s[]) {
  int i, len;
  char tmp;

  for (len=0; s[len]!='\0'&&s[len]!='\n'; len++);
  for (i=0; i<=len/2; i++) {
    tmp=s[i];
    s[i]=s[len-i];
    s[len-i]=tmp;
  }
}



    


  

