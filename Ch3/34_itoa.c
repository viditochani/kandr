#include<stdio.h>
#include<string.h>
#include<limits.h>
#define MAXLEN 100


void itoa(int n, char s[]);
void reverse(char s[]);
int main() {
  int i, j;
  char s[MAXLEN];

  i = INT_MAX;
  j = INT_MIN;
  itoa(i, s);
  printf("INT_MAX %s\n", s);
  itoa(j, s);
  printf("INT_MIN %s\n", s);
  return 0;
}
void itoa(int n, char s[]) {
  int i, sign;
  int c = 0;

  if ((sign=n) < 0) {
    if (n == INT_MIN) {
      c  = 1;
      n += 1;
    }
    n = -n;
  }

  i = 0;
  do {
    s[i++] = n%10 + '0';
  } while ((n /= 10) > 0);
  if (sign<0) 
    s[i++] = '-';
  s[i] = '\0';

  if (c > 0) {
    s[0] = ((s[0] - '0') + 1) + '0';
  }
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



