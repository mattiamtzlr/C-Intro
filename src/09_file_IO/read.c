#include <stdio.h>

/* WARN: all subsequent code assumes that the program is run with the
 * provided makefile in the root directory and that there is a directory
 * called 'files' containing the needed files. */

int main(void) {
  // open a text file "hello.txt" for reading (note the "r")
  FILE *fp1 = fopen("files/hello.txt", "r");
  // should be error-checked as it might return NULL

  // read and print a single character
  int c1 = fgetc(fp1);
  printf("%c\n", c1);

  // close the file once we're done.
  fclose(fp1);



  /* EOF (end of file) ========================================================
   *
   * We can use the special character EOF, which is defined as a macro, to read
   * an entire file, as it will be returned by fgetc at the end of the file.
   *
   * This is also why fgetc returns an int instead of a char, as EOF falls
   * outside the char range. */

  FILE *fp2 = fopen("files/hello.txt", "r");
  int c2;

  // assign value to c2 and compare it at the same time
  while ((c2 = fgetc(fp2)) != EOF)
    printf("%c", c2);

  fclose(fp2);



  /* Reading multi-line files =================================================
   *
   * We can use the fgets function to read one line at a time. It takes a
   * ponter to a char[] buffer to hold the read bytes, a max number of bytes to
   * read and a FILE* to read from.
   *
   * On EOF or error it returns NULL and automatically NUL-terminates the
   * string.*/

  FILE *fp3 = fopen("files/quote.txt", "r");
  char s[1024]; // big enough char buffer
  int line = 0;

  // read line until buffer is full (sizeof s)
  while (fgets(s, sizeof s, fp3) != 0)
    printf("%d: %s", ++line, s);

  fclose(fp3);



  /* Formatted input ==========================================================
   *
   * Using the fscanf function, we can get input from a file following a format
   * pattern similar to printf.
   * It skips leading whitespaces and returns an EOF on end-of-file or error.
   *
   * It can be unsafe to use this with untrusted input if the field widths
   * aren't specified.*/

  FILE *fp4 = fopen("files/whales.txt", "r");
  char name[1024];
  float length;
  int mass;

  while (fscanf(fp4, "%s %f %d", name, &length, &mass) != EOF)
    printf("%s whale, %d tonnes, %.1f meters\n", name, mass, length);

  fclose(fp4);
}
