#include<stdio.h>
#define MAXSIZE 1000

void escape(char s[], char t[]);
void escapeUndo(char s[], char t[]);

int main() {
  char t[] = "lakjsf	kasljfkasjdf alkfja \n alskfjalsf";
  char s[MAXSIZE];

  printf("%s \n", t);
  escape(s, t);
  printf("%s \n", s);
  escapeUndo(t, s);
  printf("%s \n", t);
  return 0;
}
void escape(char s[], char t[]) {
  int i, j;
  
  for (i=0, j=0; t[i]!='\0'; i++) {
	switch(t[i]) {
	  case '\t':
		s[j++] = '\\';
		s[j++] = 't';
		break;
	  case '\n':
		s[j++] = '\\';
		s[j++] = 'n';
		break;
	  default:
		s[j++] = t[i];
	}
  }
  s[j]='\0';
}
void escapeUndo(char s[], char t[]) {
  int i, j;
  
  for (i=0, j=0; t[i]!='\0'; i++) {
	switch(t[i]) {
	  case '\\':
		switch(t[++i]) {
		  case 't':
			s[j++] = '\t';
			break;
		  case 'n': 
			s[j++] = '\n';
			break;
		  default:
			s[j++] = '\\';
			s[j++] = t[i];
		}
		break;
	  default:
		s[j++] = t[i];
	}
  }
  s[j]='\0';
}
