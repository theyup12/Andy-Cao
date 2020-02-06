#include <stdio.h>
#define NUMBER 10
  int main(int argc, const char* argv[]){
    int charn[NUMBER];
    int c=0;
    while((c=getchar())!= EOF){
      ++charn[c];
    }
    for (int i=0; i < NUMBER;++i){
      putchar(i);
      for (int j=0; j < i; ++j ){
        putchar('*');

        putchar('\n');
      }
    }
    return 0;
  }
