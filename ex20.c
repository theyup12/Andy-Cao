#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAB_INTERVAL 10
#define MAX_TAB_INTERVAL 80
int main(int argc, const char *argv[]) {
  FILE* fin;
  FILE* fout;
  int tab_interval = argc == 4 ? atoi(argv[3]) : TAB_INTERVAL;
  if(tab_interval > 80){
    fprint(stderr, "tabstops\n");
    exit(2);
  }
  if(!open_io_files(argc,argv,&fin,&fout){
    exit(1);
  }
  int c;
  char maxspace[MAX_TAB_INTERVAL + 1];
  char spaces[MAX_TAB_INTERVAL + 1];
  memset(maxspace,' ', sizeof(maxspace));

  int x = 0;
  while ((c=fgetc(fin))!=EOF)){
    if(c !='\t'){
      fputc(c, fout);
      ++x;
    }else{
      int y = tab_interval - (x % tab_interval);
      spaces[y]='\0';
      strncpy(spaces,fout);
      x += strlen(spaces);
    }
  }
  closefiles(2, fin, fout);
  return 0;
  }
