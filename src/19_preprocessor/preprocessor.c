/* The C preprocessor ==========================================================
 *
 * Before a C pogram is compiled, it runs through the C preprocessor which
 * spits out the C code to then be compiled.
 * This preprocessor does many things, such as including other files
 * and macros.
 *
 * The #include directive tells the preprocessor to include the specified file
 * right there in the code.
 * These files can be system-wide libraries like stdio.h which are included
 * using <> angle brackets or local files which are included using "" double
 * quotes. */

#include <stdio.h>

/* The #error directive ========================================================
 *
 * This directive causes the compiler to error as soon as it is reached. This
 * is commonly used inside a conditional to prevent compilation unless some
 * prerequisite is met.
 *
 * For example, we could error if the C version is not at least C99. */

#if __STDC_VERSION__ < 199901L
  #error SDTC version must be at least C99
#endif

int main(void) {
  printf("Hello, World!\n");
}
