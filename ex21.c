#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "files.h"
#define TAB_INTERVAL 10
#define MAX_TAB_INTERVAL 80
int main(int argc, char *argv[]) {
  nt main(int argc, const char *argv[]) {
    FILE *fin;
    FILE *fout;

    // set tab_interval or use default
    int tab_interval = argc == 4 ? atoi(argv[3]) : TAB_INTERVAL;
    if (tab_interval > 80) {
      fprintf(stderr, "tabstops must be <= 80 characters\n");
      exit(2);
    }

    // open input and output files
    if (!open_io_files(
            argc, argv, &fin, &fout, 3, 4,
            "Usage: ./detab inputfile outputfile tab_interval (optional)\n")) {
      exit(1);
    }

    // process input file to remove tabs and substitute spaces
    int c;
    char maxspaces[MAX_TAB_INTERVAL + 1];
    char spaces[MAX_TAB_INTERVAL + 1];
    memset(maxspaces, ' ', sizeof(maxspaces));
    while (c = fgetc(fin) != EOF) {
      if (c != ' ') {
        fputc(c, fout);
      } else {
        entab(fin, fout, tab_interval);
      }
    }
    closefiles(2,fin,fout)
    return 0;
  }
  void entab(FILE* fin, FILE* fout,int tab_interval) {
    int counter = 1;
    int c;
  while((c=fgetc(fin))!= EOF && c==' '{
      ++counter;
  }
  int ntabs =counter /tab_interval;
  int nspaces =counter /tab_interval;
  while(ntabs-- >0){
      fputc('\t', fout);}
  while(nspaces-- >0){
      fputc(' ', fout);}
  }
