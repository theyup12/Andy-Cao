#include <stdio.h>
#define MAXLINE 1000

int mgetline(char lines[], int lim);
void copy(char copy1[], char copy2[]);

int main() {
  int length, maxnum;
  char line[MAXLINE];
  char maxline[MAXLINE];

  maxnum = 0;

  while ((length = mgetline(line, MAXLINE)) > 0) {
    if (length > maxnum) {
      maxnum = length;
      copy(maxline, line);
    }
  }

  if (maxnum > 0)
    printf("%s", maxline);
}

int mgetline(char s[], int lim) {
  int i=0,c;

  for (int i = 0; i < lim&& (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void copy(char copy1[], char copy2[]) {
  int i;
  i = 0;

  while ((copy1[i] = copy2[i]) != '\0'){
    ++i;
}
}
