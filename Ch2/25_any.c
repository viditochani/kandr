#include<stdio.h>
#define CHARS 256

int any(char s1[], char s2[]);
int main() {
  char s1[] = "abcde";
  char s2[] = "fdhij";

  printf("Location of occurence of any character from %s in %s: %d\n", s2, s1, any(s1, s2));
  return 0;
}
int any(char s1[], char s2[]) {
  int i, j;
  char count[CHARS];

  j = -1;
  for (i=0; i<CHARS; i++) 
    count[i]=0;
  for (i=0; s2[i]!='\0'; i++)
    count[s2[i]]++;
  for (i=0; s1[i]!='\0'; i++)
    if (count[s1[i]] > 0)
      return i+1;
  return j;
}


