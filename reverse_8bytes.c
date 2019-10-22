#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main (int argc, char **argv) {
  printf ("reverse_8bytes input_file output_file\n");
  if (argc != 3) {
    printf ("argc error\n");
    return 0;
  }
  FILE *f_in=fopen (argv[1], "r");
  FILE *f_out=fopen (argv[2], "w");
  if (f_in == NULL || f_out==NULL) {
    printf ("file open failed\n");
  }

  char line[1024];
  
  while (fgets (line, 1024-1, f_in)!=NULL){
    if (line[strlen(line)-1] == '\n')
      line [strlen(line)-1]='\0';
    int cursor = strlen (line)-2;
    while(cursor>=0){
      fputc(line[cursor], f_out);
      fputc(line[cursor+1], f_out);
      cursor = cursor-2;
    }
    fputc('\n', f_out);
  }


  fclose (f_in);
  fclose (f_out);

  return 1;
}
