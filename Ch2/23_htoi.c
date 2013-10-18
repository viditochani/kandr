#include<stdio.h>
#include<string.h>

int iswhitespace(char c) {
  return (c==' ' || c=='\t' || c=='\n');
}
int getdigit(char c) {
  if (c >= '0' && c <= '9') 
    return c - '0';
  else if ((c >= 'a' && c <= 'f') || (c>='A' && c<='F'))
    return 10 + c - (c>='a'&&c<='f'?'a':'A');
  return -1;
}

int htoi(char *str) {
  int i, c, x;
  int len = strlen(str);

  x = 0;
  for (i=0; iswhitespace(str[i]); i++);

  if (str[i]=='0' && (str[i+1]=='x' || str[i+1]=='X'))
    i += 2;
  while((c=getdigit(str[i++]))!=-1) {
    x *= 16;
    x += c;
  }
  return x;
}
 
int main() {
  char s[] = "0xFF";
  char s2[] = "0xff";
  char s3[] = "   ff";
  char s4[] = "  9";
  char s5[] = " 5zlksfj";

  printf("%10s is %d\n", s, htoi(s));
  printf("%10s is %d\n", s2, htoi(s2));
  printf("%10s is %d\n", s3, htoi(s3));
  printf("%10s is %d\n", s4, htoi(s4));
  printf("%10s is %d\n", s5, htoi(s5));

  return 0;
}




