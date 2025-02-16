#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Void pointers ==============================================================
 *
 * Sometimes it's useful to have a pointer to a thing that we don't know the
 * type of. There are two common use cases for this:
 *
 *   1. A function operating on data byte-by-byte, for example memcpy().
 *
 *   2. A function is calling a function we passed to it (a callback) and it
 *   is passing us data. We know the type but the function calling us doesn't.
 *
 *
 * Let's use memcpy() as an example:
 *
 *   void *memcpy(void *s1, void *s2, size_t n)
 *
 * It copies n bytes of memory from s2 into memory at s1.
 * We can use pointer conversion (see further down) to create our own version
 * which handles only strings: */

void *str_memcpy(void *dest, void *src, int count) {
  // convert to char*
  char *s = src, *d = dest;

  while (count--) {
    *d++ = *s++; // dereference and copy chars
  }

  // usually return dest, as that might be useful to the caller.
  return dest;
}



typedef struct animal {
  char *name;
  int  leg_count;
} animal;

/* We define a comparison function for animals, which will be called by the
 * builtin qsort() in stdlib. Ignore the const for now.*/
int compare(const void *elem1, const void *elem2) {
  const animal *a1 = elem1;
  const animal *a2 = elem2;

  // sort ascending by leg count
  if (a1->leg_count > a2->leg_count) return 1;
  if (a1->leg_count < a2->leg_count) return -1;
  return 0;
}


int main(void) {
  char s[] = "Goats!";
  char t[100];

  str_memcpy(t, s, 7); // also copy NUL-terminator
  printf("%s\n", t);


  int a[3] = {42, 37, 19};
  int b[3];

  memcpy(b, a, 3 * sizeof(int));
  printf("%d %d %d\n", b[0], b[1], b[2]);



  /* Limits of void pointers ==================================================
   *
   * Void pointers don't support pointer arithmetic and they cannot
   * dereferenced, which includes using the arrow (->) operator and array
   * notation.
   * These things are imposssible, as they rely on knowing the sizeof the type
   * of the pointed-to data, which isn't known for a void*.
   *
   * What we can do, is convert a void* to a pointer to another type: */

  char c = 'X';

  void *p = &c; // void pointer to 'X'
  char *q = p;  // char pointer to 'X'

  #ifdef ERROR
  printf("%c\n", *p);
  #endif

  printf("%c\n", *q);



  animal animals[4] = {
    {.name="Dog", .leg_count=4},
    {.name="Monkey", .leg_count=2},
    {.name="Antelope", .leg_count=4},
    {.name="Snake", .leg_count=0}
  };

  /* Signature of qsort():
   *  - the array to sort
   *  - the number of elements in the array
   *  - the size of each element
   *  - the function to compare them */
  qsort(animals, 4, sizeof(animal), compare);

  for (int i = 0; i < 4; i++)
    printf("%d: %s\n", animals[i].leg_count, animals[i].name);
}

