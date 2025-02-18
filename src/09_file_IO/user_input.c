#include <stdio.h>

int main(void) {
  /* Controlled user input ====================================================
   *
   * As scanf returns the number of characters correctly read, or EOF if there
   * will be a conversion error, we can use that to control user input quite
   * efficiently. */

  int i, res = 0;

  do {
    printf("Enter a number between 1 and 10: ");
    fflush(stdout); // make sure the above is actually printed
    res = scanf("%d", &i);
    if (res != 1) {
      printf("That's not what I want\n");
      // empty the stdin buffer
      while (!feof(stdin) && !ferror(stdin) && getc(stdin) != '\n');
    }
  } while (!feof(stdin) && !ferror(stdin) && (res != 1 || i < 1 || i > 10));

  printf("Great Job! You entered %d!\n", i);
}
