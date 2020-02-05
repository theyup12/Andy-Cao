#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUMBER 10

int main(int argc, char *argv[]) {
  int c, line, word, space;
  char aword[100], spaces[100];  // buffers
  int inword;

  inword = line = word = space = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      if (line + word > MAX_NUMBER)
        putchar('\n');
      prints(aword, word);
      putchar('\n');
    } else if (c == ' ' || c == '\t') {
      if (inword) {
        inword = 0;
        if (line + word > MAX_NUMBER) {
          putchar('\n');
          prints(aword, word);
          line = word;
          word = 0;
        } else {
          prints(aword, word);
          line += word;
          word = 0;
        }
      }
      spaces[space++] = c;
    } else {
      if (!inword) {
        inword = 1;
        prints(spaces, space);
        line += space;
        space = 0;
      }
      aword[word++] = c;
    }
  }

  return 0;
}

void prints(char line[], int n) {
  int i;

  for (i = 0; i < n; i++)
    putchar(line[i]);
}
}
