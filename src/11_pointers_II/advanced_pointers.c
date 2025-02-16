#include <stdio.h>

/* Subtracting pointers from each other =======================================
 *
 * If we have two pointers pointing to elements of the same array, we can
 * subtract them to find the amount of items between them.
 *
 * As strings are just char*s in C, we can use this to write our own strlen
 * function. */

int my_strlen(char *s) {
  char *end = s;

  // increment pointer until it points to the last character
  while (*end != '\0')
    end++;

  return end - s;
}



int main(void) {
  /* Pointer arithmetic =======================================================
   *
   * If we have a pointer to a type, adding one to the pointer omves to the
   * next of that type directly after it in memory.
   * We must be careful, that the pointer points to valid data, as otherwise
   * we'll get a segfault when dereferencing. */

  int a[] = {11, 22, 33, 44, 55, -1};
  int *p  = a; // pointer to a[0]

  printf("%d\n", *p);       // prints first element
  printf("%d\n", *(p + 1)); // prints second element!

  /* NOTE: Adding 1 to an int pointer actually adds sizeof(int) = 8 to the
   * pointer. Same goes for other types. */


  // we can even use a loop:
  for (int i = 0; i < 5; i++)
    printf("%d ", *(p + i));
  printf("\n");


  // or while loop to increment the pointer itself until we reach the sentinel
  while (*p != -1) {
    printf("%d ", *p);
    p++;
  }
  printf("\n");


  printf("%d\n", my_strlen("Hello, World!"));
}



/* Array/Pointer Equivalence ==================================================
 *
 * As we have seen before, arrays and pointers are pretty much the same thing,
 * to the point where the following holds:
 *
 *   a[b] == *(a + b)
 *
 * To be entirely correct this should be a[b] == (*((a) + (b))) but hey.
 *
 * The one big difference, is that a pointer can be modified to point to a
 * different address, but an array variable cannot be modified.
 *
 *
 * This is also why the following two signatures are equivalent: */

int foo(char *s);
int foo(char s[]);
