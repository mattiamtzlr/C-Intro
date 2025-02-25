/* WARNING: The provided Makefile will not really work with this file, use
 *   gcc -o foo arguments.c
 * and then
 *   ./foo <arg1> <arg2> ...
 * instead. */

#include <stdio.h>
#include <stdlib.h>

/* Command line arguments =====================================================
 *
 * To pass command line arguments to a C program we use the following defintion
 * of main(), allowing us to access the argument vector (argv) containing argc
 * elements.
 *
 * The first (index 0) of these elements is always the name of the executable
 * itself.
 *
 * After the last (index argc) element of argv, there is always a pointer to
 * NULL, providing an alternate way to loop through the argv - until the
 * pointer is NULL. */

int main(int argc, char *argv[]) {
  int sum = 0;

  /* You can change the value of argv[0] (as well as the others) resulting in
   * the actual command to invoke the program being changed. very cool
   *
   * strcpy(argv[0], "Hello"); */

  if (argc > 0) {
    char *arg;
    char *err;

    for (int i = 1; i < argc; i++) {
      arg = argv[i];
      sum += strtoul(arg, &err, 10);

      if (*err != '\0') {
        fprintf(stderr, "Error while converting argument %d '%s' to integer\n",
                i, arg);
        return 1;
      }
    }
  }

  int x;

  printf("Sum: %d\n", sum);
  return 0;
}
