#include <stdio.h>

void removec(int c);
void comment(void);
/*delete comment line*/
int main(int argc, char* argv[]) {
  int c;

  printf(" To Check /* if the comment deleted or not */ \n");

  while ((c = getchar()) != EOF)
    removec(c);

  return 0;
}

void removec(int c) {
  int d = 0;
  if (c == '/' && (d = getchar()) == '*') {
      comment();}
    else if (d == '/') {
      putchar(c);
      removec(d);
    } else {
      putchar(c);
      putchar(d);
    }
  }
void comment() {
  int c, d;

  c = getchar();
  d = getchar();

  while (c != '*' || d != '/') {
    c = d;
    d = getchar();
  }
}
