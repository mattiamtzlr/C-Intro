#include <stdio.h>

/* Simple Macros ==============================================================
 *
 * A macro is an identifier which gets expaneded to the defined piece of code
 * by the preprocessor, like a placeholder. They are defined using #define.
 *
 * Macros persist across multiple files, which is why the trick used in
 * 17_multifile/foo.h to only ever include a header file once. */

#define HELLO "Hello, World!"
#define PI 3.14159
#define ANSWER 42

/* Macros don't necessarily need a value: */
#define SOMETHING


int main(void) {
  /* We can check whether a macro has been defined or not with the #ifdef and
   * #ifndef directives, which have to be followed at some point by a #endif.
   * The code between these will be included by the preprocessor based on
   * whether the condition is given or not.*/

#ifdef SOMETHING
  printf("%s\n", HELLO);
#else
  printf("%.5f\n", PI);
#endif


  /* If we no longer need a macro we can undefine it with #undef */

#undef SOMETHING

#ifndef SOMETHING
  printf("%d\n", ANSWER);
#endif



  /* Built-in Macros ==========================================================
   *
   * There are some built-in macros, which are used in the code below. They are
   * identified by their dunder name. */

  printf("Function:     %s\n", __func__);
  printf("File:         %s\n", __FILE__);
  printf("Line:         %d\n", __LINE__);
  printf("Compile time: %s @ %s\n", __DATE__, __TIME__);
  printf("C version:    %ld\n", __STDC_VERSION__);
}
