#include <stdio.h>

// see below
void loop(int *restrict x) {
  for (int i = 0; i < 100; i++)
    *x += i;
}



int main(void) {
  /* Type Qualifiers ==========================================================
   *
   * Type qualifiers are additional attributes we can give to a type to control
   * its behaviour.
   *
   * First example: const, pretty self-explanatory 
   *
   * see 05_pointers_I/pointers.c for the relation of pointers and const. */

  const int x = 2;
  void foo(const int x);

  // check this out
  int const *const p = &x;



  /* restrict (very rare) =====================================================
   *
   * TLDR: ignore it, if used correctly, may increase performance, if used
   *       incorrectly, it fucks shit up.
   *
   * restrict is a qualifier, hinting to the compiler that a piece of memory
   * will only be accessed by one pointer and never another.
   *
   * This could for example increase performance, when a pointer is repeatedly
   * dereferenced in a loop. The compiler could then cache the value in a
   * register and only write back the final value to memory. If any other
   * pointer were to access that memory in the meantime, it'd be incorrect. */

  int y = 3;
  loop(&y);
  printf("%d\n", y);



  /* volatile (also very rare) ================================================
   *
   * volatile tells the compiler that the given value could change based on
   * stuff happening outside the program, for example because of MMIO hardware.
   *
   * The value must thus be looked up every time and shouldn't be cached. */

  volatile int *q;
}
