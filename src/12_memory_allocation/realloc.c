#include <stdio.h>
#include <stdlib.h>

int main(void) {
  /* Chaning allocated size with realloc() ====================================
   *
   * If we allocate some space in memory, and later it turns out that we need
   * more space, we can use the realloc function in stdlib, which cleverly
   * allocates more space.
   *
   * It takes a pointer to an already allocated region and a new size (in
   * bytes!), and returns either a new pointer, if the memory had to be copied,
   * or the same pointer, if there was enough 'adjacent' space.
   *
   * As an example, let's allocate an array of 20 floats, then change our minds
   * and reallocate an array of 40 floats. */

  float *p = malloc(sizeof(*p) * 20);
  for (int i = 0; i < 20; i++)
    p[i] = i / 20.0;

  /* Copy returned pointer into new variable, in case NULL is returned, so that
   * we don't lose the original pointer variable. */
  float *q = realloc(p, sizeof(*p) * 40);
  if (q == NULL) {
    fprintf(stderr, "Error while reallocating\n");
    return 1;
  }

  /* Reallocation must have been successful, we can use the new pointer in
   * place of the old one. This is just for convenience, but pretty common. */
  p = q;
  for (int i = 20; i < 40; i++)
    p[i] = 1.0 + (i - 20) / 20.0;

  for (int i = 0; i < 40; i++)
    printf("%.2f ", p[i]);
  printf("\n");

  free(p); // this simultaneously frees q, as they point to the same region



  /* realloc() with NULL ======================================================
   *
   * The following two lines are equivalent, which is useful if we have a
   * reallocation loop and don't want to special-case the first malloc. */

  void *a = malloc(42);
  void *b = realloc(NULL, 42);

  free(a);
  free(b);
}
