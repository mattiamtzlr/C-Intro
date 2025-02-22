#include <stdio.h>


/* static =====================================================================
 *
 * Let's start with 'static'. In block scope, static declares a variable as a
 * single instance shared across calls to that block. Thus the value persists
 * across function calls for example. Static values are always initialized
 * to zero. */

void counter(void) {
  static int count = 1;

  printf("'counter' has been called %d time%s\n", count, count > 1 ? "s" : "");
  count++;
}

int main(void) {
  /* Storage-class specifiers =================================================
   *
   * Specifiers are similar to type quantifiers, they also give the compiler
   * more information about the type of a variable. */

  counter();
  counter();
  counter();
  counter();



  /* The extern specifier =====================================================
   *
   * This specifier gives us a way to refer to objects declared in other source
   * files.
   *
   * For example, if we have the file foo.c containing only a file scope
   * declaration of a variable 'a', we can do the following to access it: 
   *
   *   extern int a;
   *   printf("%d\n", a);
   *
   * For this to work, both files must be passed to the compiler. */



  /* The register specifier ===================================================
   *
   * This keyword hints to the compiler that the variable is frequently-used,
   * and should thus maybe be stored in a register. The compiler doesn't have
   * to agree.
   *
   * This is pretty rare, as modern C compilers are very good.
   *
   * Also, if the value actually ends up in a register, it won't be in memory,
   * thus creating a pointer to a register variable is not allowed. */

  register int a;
  for (a = 0; a < 20000; a++)
    if (a % 5000 == 0) printf("%d ", a);

  printf("\n");
}
