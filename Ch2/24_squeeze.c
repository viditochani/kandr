#include<stdio.h>
#define CHARS 256

void squeeze(char s1[], char s2[]);
int main() {
  char s1[] = "abcde";
  char s2[] = "efagh";

  printf("Before s1:%s, s2:%s\n", s1, s2);
  squeeze(s1, s2);
  printf("After s1:%s, s2:%s\n", s1, s2);
  return 0;
}
void squeeze(char s1[], char s2[]) {
  int i, j;
  char count[CHARS];

  for (i=0; i<CHARS; i++) 
    count[i] = 0;
  for (i=0; s2[i]!='\0'; i++) 
    count[s2[i]]++;
  for (i=j=0; s1[i]!='\0'; i++)
    if (count[s1[i]] == 0)
      s1[j++] = s1[i];
  s1[j++] = '\0';
}


