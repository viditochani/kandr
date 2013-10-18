#include<stdio.h>

#define CHAR 0
#define STRING 1
#define SL_COMMENT 2
#define ML_COMMENT 3
#define CODE 4

/* This is the main function. Random comment.. 
 * " * string inside '"' // ''af'
 * lksf ' sf'a ''" "'asf '"comment" */
int main() {
  int c, state; 

  state = CODE;
  char random_string[] = "lsfjaa / \\ / \\ / \n / / slakfa /* aksjf ";
  // Random Comment.. alskfj /* kalfj */
  while((c=getchar()) != EOF) {
    if (c=='/' && state==CODE) {
      c=getchar(); 
      if (c=='*' && state != SL_COMMENT) 
        state = ML_COMMENT; 
      else if (c=='/' && state != ML_COMMENT)
        state = SL_COMMENT;
      else
        printf("/%c", c);
    } else if (c=='\\' && (state==STRING || state==CHAR)) {
      c = getchar();
      printf("\\%c", c);
      continue;
    } else if (c=='"' && state==CODE) 
      state = STRING;
    else if (c=='"' && state==STRING)
      state = CODE;
    else if (c=='\'' && state==CODE)
      state = CHAR;
    else if (c=='\'' && state==CHAR) 
      state = CODE;
    else if (c=='*' && state==ML_COMMENT) { 
      c = getchar();
      if (c=='/') 
        state=CODE; 
      continue;
    } else if (c=='\n' && state==SL_COMMENT) 
      state=CODE; 

    // Print character
    if (state!=SL_COMMENT && state!=ML_COMMENT)
      printf("%c", c);
  }
}
