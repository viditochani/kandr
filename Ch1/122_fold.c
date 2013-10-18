#include<stdio.h>
#include<stdlib.h> 

#define TEXT 0
#define SL_COMMENT 1
#define STRING 2
#define MAXLEN 100
#define MAXWORD 1000

// this is a really long commmenttt to test if comments are wrapped around properly and nothing goes wrong lajfl akjsfl kjalkj flkajl kjflakj fljasl kjfal jljalk jflkaj lkfjlaksj lfjsa ljalk jlafkj lkjaskl fjaljk lfja ljal jfaljk flkaj fkaj lkajlk
int main(int argc, char **argv) {
  int i, len;
  int c;
  int state = TEXT;
  char word[MAXWORD];

  char test[]="this is really long string to test if string are wrapped properly kasjflk ajsflk jlakj flkjads klsfjal ka // als;jf las;\"  kajslk fjalksj fl/* kajlskf  lasj lkfj alkfj lkasjflk jalskdj fklasj fajs lkfjaslkjf lkjalk fjlaksj lkasj lfskaj flkaj lkjasl kjlfakjl jal jfalsj";
  i = len = 0;
  while ((c=getchar()) != EOF) {
    if (c=='\n') {
      len = 0;
      if (state == SL_COMMENT) state = TEXT;
    } else if (c=='"' && state==STRING) {
      state = TEXT;
    } else if (c=='"' && state==TEXT) {
      state = STRING;
    } else if (c=='/' && state==TEXT) {
      len += 1;
      word[i++] = '/';

      c = getchar();
      if (c=='/') 
        state = SL_COMMENT; 
    } else if (c=='\\' && state==STRING) {
      len += 1;
      word[i++] = '\\';

      c = getchar();
    } else if (c==' ' || c=='\t') {
      if (i!=0) {
        word[i] = '\0';
        printf("%s", word);
      } 
      i = 0;
    } 
    word[i++] = c;

    len += 1;
    if (len > MAXLEN) {
      if (state == STRING) printf("\\\n");
      if (state == TEXT) printf("\n");
      if (state == SL_COMMENT) printf("\n//");
      len = 0;
    }
    
    // Special case to handle if the word is really big
    if (i>=MAXLEN || i>=MAXWORD) 
      printf("%s", word);
  }
  // a really big useless code line
  i = 2 + 2 + 4 + 85 + 9 * 1 * 3 / 5 - 1 + 3 - (13 + 3) * (2^2 >> 1) / (2^2 >> 1) + (2 * 0 * 1 * 5 * 2 * 2);
  return 0;
}
    

