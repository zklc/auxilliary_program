#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main (int argc, char **argv) {
  printf ("%s input_file\n", argv[0]);
  if (argc != 2) {
    printf ("argc error\n");
    return 0;
  }
  FILE *f_in=fopen (argv[1], "r"); 
  FILE *f_out =NULL;
  char line[1024];
  char file_name[1024];
  int current_count = 0;
  while (fgets (line, 1024-1, f_in)!=NULL){
    if (current_count %1024 == 0) {
      if (f_out != NULL) {
        fclose (f_out);
      }
      sprintf (file_name,"%d.txt", current_count/1024);
      f_out=fopen (file_name, "w");
      
   }
    fprintf (f_out, "%s", line);  //included '\n'
    current_count++;
  }

  fclose (f_in);
  return 0;
}
