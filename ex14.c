#include <stdio.h>
void initialize(int *array) {
  for (int i = 0; i < 26; i++)
    array[i] = 0;
}
int main() {
  int array[26];
  int c, i, temp;
  initialize(array);
  while ((c = getchar()) != EOF) {
    while (c != '\n') {
      if ((c >= 65 && c <= 90)) {
        temp = c;
        temp -= 65;
        ++array[temp];
      } else if (c >= 97 && c <= 122) {
        temp = c;
        temp -= 97;
        ++array[temp];
      }
      c = getchar();
    }
    for (i = 0; i < 26; i++) { // putchar(i);
      if (array[i] == 0)
        continue;
      printf("%d", i + 1);
      while (array[i]--)
        putchar('*');
      putchar('\n');
    }
    initialize(array);
  }
}
