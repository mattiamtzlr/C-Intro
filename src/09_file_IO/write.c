#include <stdio.h>

int main(void) {
  /* Writing text files =======================================================
   *
   * In much the same spirit as reading text files, we can use the fputc, fputs
   * and fprintf functions to write text streams.
   *
   * To do this, we use fopen with the "w" paramters, which will instantly
   * truncate an existing file to 0 bytes for overwrite. */

  FILE* fp = fopen("files/output.txt", "w");
  int x = 32;

  fputc('B', fp);
  fputc('\n', fp);
  fprintf(fp, "x = %d\n", x);
  fputs("Hello, World!\n", fp);

  fclose(fp);

  printf("Successfully wrote to files/output.txt\n");
}
