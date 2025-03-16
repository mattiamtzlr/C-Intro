#include <stdlib.h>
#include <stdio.h>

/* Returning from main and exit() ==============================================
 *
 * The main() function is the only one which implicitly returns at the end,
 * specifically with value EXIT_SUCCESS = 0.
 * Another way to exit a program is the exit() function in stdlib, where we can
 * pass an exit status: EXIT_SUCCESS (0) or EXIT_FAILURE (1) */



void on_exit_1(void) {
  printf("exit handler 1 called!\n");
}

void on_exit_2(void) {
  printf("exit handler 2 called!\n");
}



int main(void) {
  /* Exit handlers =============================================================
   *
   * Using the atexit() function in stdlib, we can specify one or multiple exit
   * handlers which will be called in reverse order of registration when the
   * program exits. */

  atexit(on_exit_1);
  atexit(on_exit_2);

  printf("%d %d\n", EXIT_SUCCESS, EXIT_FAILURE);
  printf("exiting...\n");
}
