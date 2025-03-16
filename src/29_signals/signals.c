#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/* Signal handling =============================================================
 *
 *  WARN: Generally it is better and easier to use the sigaction() family of
 *        functions, as everything below is undefined behaviour.
 *
 * Signals are raised based on external events, and we can configure a program
 * to handle the signal and optionally continue afterwards. The handler is like
 * a function that is automatically called when the signal is raised.
 *
 * The signals which are defined in the C spec are the following:
 *   SIGABRT  Abnormal termination—what happens when abort() is called
 *   SIGFPE   Floating point exception
 *   SIGILL   Illegal instruction
 *   SIGINT   Interrupt - usually the result of CTRL-C being hit
 *   SIGSEGV  Segmentation Violation: invalid memory access
 *   SIGTERM  Termination requested
 *
 * To handle them, we use the signal() function in <signal.h> which takes as
 * arguments a signal and an action, which can be
 *  - a pointer to a handler function
 *  - SIG_IGN to ignore the signal
 *  - SIG DFL to use the default handler for the signal
 *
 * We can for example deactivate CTRL-C during input, by ignoring SIG_INT. */

void sigint_handler(int signum) {
  /* The compiler is allowed to reset the signal handler to SIG_DFL when the
   * handler is called, thus we have to reset it again to ours. */
  signal(SIGINT, sigint_handler);

  printf("\nWell done!\n");
  fflush(stdout);
  exit(0);
}



int main(void) {
  char s[1024];

  /* ignore interrupt signal */
  signal(SIGINT, SIG_IGN);

  printf("Try exiting with CTRL-C (hit RETURN to continue)\n");
  fgets(s, sizeof s, stdin);

  /* use custom handler */
  signal(SIGINT, sigint_handler);

  printf("Now you can exit using CTRL-C: ");
  fflush(stdout);
  for (;;);
}
