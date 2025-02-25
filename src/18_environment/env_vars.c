#include <stdio.h>
#include <stdlib.h>

/* Environment variables ======================================================
 *
 * The environment of in which a program is run is usually a shell, which might
 * have some variables of its own defined. Some examples of these are:
 *
 *   HOSTNAME, LANG, OS, PATH, SHELL, TERM, USER
 *
 * To access these from within a C program, we can use the stdlib getenv()
 * function, which will return a pointer to the string, or NULL if it doesn't
 * exist. */

int main(void) {
  char *hostname = getenv("HOSTNAME");
  char *ostype = getenv("OSTYPE");
  char *shell = getenv("SHELL");
  char *user = getenv("USER");

  if (hostname == NULL || ostype == NULL || shell == NULL || user == NULL) {
    printf("Error: Could not access one or more environment variables\n");
    return 1;
  }

  printf("HOSTNAME = %s\n", hostname);
  printf("OSTYPE   = %s\n", ostype);
  printf("SHELL    = %s\n", shell);
  printf("USER     = %s\n", user);
}
