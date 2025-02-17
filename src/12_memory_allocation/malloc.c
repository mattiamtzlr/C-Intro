#include <stdio.h>
#include <stdlib.h>

int main(void) {
  /* Memory allocation with malloc() and free() ===============================
   *
   * In C, we can manually allocate and deallocate memory on the heap, in
   * contrast to local variables on the stack. Whenever we allocate memory
   * ourselves, we also have to free it after use, otherwise, we'll get a
   * memory leak.
   *
   * The malloc() function in stdlib takes a number of bytes to allocate and
   * returns a void pointer to that block of newly allocated memory.
   *
   * To know how many bytes to allocate, we usually use sizeof.
   * After we no longer need the allocated space, we have to call free() with
   * the same pointer as an argument. */

  int *p = malloc(sizeof(int)); // allocate sizeof(int) bytes of space
  *p = 42;                      // store something in that region

  printf("%d\n", *p);
  free(p);                      // free after last use

  /* In the above example, there's really no benefit to doing things manually,
   * as we could have just as well used an automatic int on the stack. */

  int *q = malloc(sizeof(*q));  // shorthand for the above allocation
  free(q);



  /* Error checking ===========================================================
   *
   * As memory allocation can go wrong (in which case NULL is returned by
   * malloc), it is usually smart to handle such errors, for example by using
   * the following common pattern. */

  int *x;

  if ((x = malloc(sizeof(*x) * 10)) == NULL) {
    printf("Error allocating 10 ints\n");
    return 1; // cry about it
  }

  free(x);
}
