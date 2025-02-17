#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT 10

int main(void) {
  /* Allocating space for arrays ==============================================
   *
   * To allocate space for an array of n elements, each of type T, it is enough
   * to call malloc(sizeof(T) * n).
   *
   * After allocating, we might want to clear the memory region to zero, before
   * using it. This can be done with memset() in string.h. */

  int *p = malloc(sizeof(int) * COUNT);
  memset(p, 0, COUNT); // region, value, count

  for (int i = 0; i < COUNT; i++)
    p[i] = i * 5; // remember: p[i] = *(p+i)

  for (int i = 0; i < COUNT; i++)
    printf("%d ", p[i]); // remember: p[i] = *(p+i)
  printf("\n");

  free(p);



  /* Alternative: calloc() ====================================================
   *
   * calloc() in stdlib works similarly to malloc, but it takes the size of an
   * element and the number of those elements we want to allocate space for.
   * It also clears the allocated region to 0 for us.
   *
   * Memory allocated by calloc() should also be freed by free() eventually. */

  int *q = calloc(COUNT, sizeof(int));
  free(q);
}
