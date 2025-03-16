#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Quick exits =================================================================
 *
 * Similarly to normal exits, we can use a quick_exit() call to exit the
 * program, except:
 *  - open files might not be flushed (including stdout, stderr)
 *  - temporary files might not be removed
 *  - exit handlers defined with atexit() won't be called
 *
 * We can still register exit handlers by using at_quick_exit().
 *
 *
 * If we need to exit even quicker than that, we can nuke the entire program by
 * calling _Exit() and the program will quit right fucking then. */

void quick_exit_handler(void) {
  printf("quick exit handler called\n");
}

void exit_handler(void) {
  printf("normal exit, this won't be called!\n");
}



/* assert() and abort() ========================================================
 *
 * Asserts are used to catch should-never-happen type errors, and are usually
 * not meant to be seen by the end-user.
 *
 * Aborting is used to indicate that something has gone horribly wrong and we
 * want to signal this to the environment. Aborting will not necessarily clean
 * up after itself. Under the cover this works by raising a SIGABRT, ending the
 * process and usually dumping the core. */

int main(void) {
  /* registering exit handlers */
  at_quick_exit(quick_exit_handler);
  atexit(exit_handler);

  assert(20 > 10);

  if (10 - 5 < 0)
    abort();

  printf("quick-exiting...\n");
  quick_exit(0);
}
