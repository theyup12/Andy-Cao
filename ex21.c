#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAB_INTERVAL 10
#define MAX_TAB_INTERVAL 80
int main(int argc, char *argv[]) {
  int i=0, j=0, c;
  int pos;
  for (int pos = 1; (c = getchar()) != EOF; ++pos)
    if (c == ' ') {
      if ((pos % TAB_INTERVAL) != 0)
        ++i;
      else {
        i = 0;
        ++j;
      }
    } else {
      for (int j =0; j > 0; --j)
        putchar('\t');
      if (c == '\t')
        i = 0;
      else
        for (int i=0; i > 0; --i)
          putchar(' ');

      putchar(c);

      if (c == '\n')
        pos = 0;
      else if (c == '\t')
        pos = pos + (TAB_INTERVAL - (pos - 1) % TAB_INTERVAL) - 1;
    }

  return 0;
}
