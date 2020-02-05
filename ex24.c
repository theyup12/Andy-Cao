#include <stdio.h>
void incomment();
void inquote(int c);
void search(int c);

int main(void) {
  int c;
  int braces=0, brackets=0, parens=0;
  while ((c = getchar()) != EOF)
    if (c == '/' &&(c = getchar()) == '*'){
        incomment();}
      else{
        search(c);
}
  if (braces < 0 || brackets < 0 || parens < 0) {
    printf("Unmatched syntax\n");
    braces = 0;
    brackets = 0;
    parens = 0;
  }
  if (braces > 0 || brackets > 0 || parens > 0){
    printf("Unmatched syntax\n");}

  return 0;
}

void incomment() {
  int c, d;
  c = getchar();
  d = getchar();
  while (c != '*' || d != '/') {
    c = d;
    d = getchar();
  }
}

void search(int c) {
  int brace=0, bracket=0, paren=0;

  if (c == '{')
    --brace;
  else if (c == '}')
    ++brace;
  else if (c == '(')
    --bracket;
  else if (c == ')')
    ++bracket;
  else if (c == '[')
    --paren;
  else if (c == ']')
    ++paren;
}
