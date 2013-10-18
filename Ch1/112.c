#include<stdio.h>

#define IN 0
#define OUT 1 

int main() {
  int c;
  while((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t'
