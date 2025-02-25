/* WARNING: The provided Makefile will not work with this file, use
 *   gcc -o main main.c foo.c && ./main
 * instead. */

#include <stdio.h>

/* Multifile Projects =========================================================
 *
 * Usually, C programs are made up of many files that are all compiled and
 * lined together upon compilation.
 *
 * If we pass all necessary files to the compiler, we can easily use functions
 * from other files (e.g. add from foo.c) in our code. However, we have to
 * declare a prototype / header for every function, which can become tedious.
 *
 * This is where header files (.h) come in. They contain headers for every
 * function in the corresponding source file and usually share the same name
 * as that source file.
 * These can then be included as follows: */

#include "foo.h"

int main(void) {
  printf("%d\n", add(2, 3));
}
