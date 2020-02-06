#include <stdio.h>
#define MAXLINE 500

int mgetline(char line[], int lim);
void removet(char rline[], int length1);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = mgetline(line, MAXLINE)) > 0)
    removet(line, len);
    printf("%s\n", line);

  return 0;
}

int mgetline(char s[], int lim) {
  int i, c;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  return i;
}

void removet(char s[], int length) {
  int head, tail;
  for(head = 0; s[head] ==' '|| s[head]=='\t'; head++);
  for(tail = length; s[tail] ==' '|| s[tail]== '\t'|| s[tail]== '\n'|| s[tail]== '\0'; --tail);
  if(tail-head >=0){
    for(int i = head; i <= tail; i++)
    putchar(s[i]);
    putchar('\n');
    putchar('\0');
  }
}
