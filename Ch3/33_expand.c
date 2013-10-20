#include<stdio.h>
#include<ctype.h>
#define MAXSIZE 1000

void expand(char s1[], char s2[]);
int main() {
  char s2[MAXSIZE];
  char s1[] = "A sample string -a a-z A-Z a-b-c a-z0-9 a-Z A-z 0-1-2-";

  printf("%s \n", s1);
  expand(s1, s2);
  printf("%s \n", s2);
  return 0;
}
/* This assumes s2 has sufficient space, otherwise the behavior will be undefined */
void expand(char s1[], char s2[]) {
  int i, j, k;
  char p, n;

  for (i=0, j=0; s1[i]!='\0'; i++) {
    if (s1[i]=='-' && isalnum(s1[i-1]) && isalnum(s1[i+1])) {
      char p=s1[i-1];
      char n=s1[i+1];

      if (p>n || (islower(p) && !islower(n)) || (isupper(p) && !isupper(n))) {
        s2[j++] = '-';
      } else {
        for (k=1; k<(n-p); k++) {
          s2[j++] = p+k;
        }
      }
    } else {
      s2[j++] = s1[i];
    }
  }
}




