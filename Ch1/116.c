#include<stdio.h>
#define MAXLEN 1000

// stdio.h has getline
int getline2(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
  int len;
  int max;
  char line[MAXLEN];
  char longest[MAXLEN];

  max = 0;
  while((len = getline2(line, MAXLEN)) > 0) 
    if (len > max) {
      max = len;
      copy(longest, line);
      if (line[len-1] != '\n') {
        while (getchar()!='\n') 
          max++;
      }
    }
  if (max > 0)
    printf("%d \n %s", max,  longest);
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
void copy(char to[], char from[]) {
  int i;
  i=0;

  while ((to[i] = from[i]) != '\0')
    ++i;
}




    


  

