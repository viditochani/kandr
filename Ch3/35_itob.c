#include<stdio.h>
#include<string.h>

#define MAXLEN 100

char getDigit(int n);
void itob(int n, char s[], int b);
void reverse(char s[]);
int main() {
  char s[MAXLEN];
  int i = 255;

  itob(i, s, 8);
  printf("In octal %s\n", s);
  itob(i, s, 16);
  printf("In hex %s\n", s);
  itob(i, s, 2);
  printf("In bin %s\n", s);
  itob(i, s, 29);
  printf("In other %s\n", s);
  return 0;
}
char getDigit(int n) {
  if (n<=9) {
    return (char)(n+'0');
  } else {
    return (char)((n-10) + 'a');
  }
}
/* Can handle upto base 36 */
void itob(int n, char s[], int b) {
  int i=0, j=n;
  while (j>0) {
    s[i++] = getDigit(j%b);
    j /= b;
  }
  s[i] = '\0';
  reverse(s);
}

// reverse doesn't exist in standard library anymore
void reverse(char s[]) {
  int i,j;
  char c;
  for (i=0, j=strlen(s)-1; i<=j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}



