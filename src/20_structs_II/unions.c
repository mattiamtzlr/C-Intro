#include <stdio.h>

/* Unions ======================================================================
 *
 * Unions are basically like structs, except the fields overlap in memory,
 * occupying as much space as the largest field. This also means we can only use
 * one field at a time. It's a way of reusing memory space for different types
 * of data. */

union foo {
  int a;
  char c;
  double y;
};

/* The above will use as much memory as the double type (usually 8 bytes). */



int main(void) {
  printf("sizeof(foo) = %zu bytes\n", sizeof(union foo));

  union foo x;

  x.a = 42;
  printf("x.a = %d\n", x.a);

  x.c = 'A';
  printf("x.c = %c\n", x.c);

  x.y = 3.14159;
  printf("x.y = %g\n", x.y);



  /* Type punning ==============================================================
   *
   * We can write write to one field of the union and read from another, which
   * is called type punning. It works as the fields share the same memory.
   *
   * For example, after having written to field 'y' above, we can read the field
   * 'c'. We'll get whatever integer value is represented by the FP
   * representation of 'y'. */

  printf("\nx.a = %d (after setting x.y)\n", x.a);


  /* Or, we can set x.a, and read back x.c to get whatever character is
   * represented by x.a. */

  x.a = 69;
  printf("x.c = %c (after setting x.a)\n", x.c);



  /* Pointers to unions ========================================================
   *
   * If we have pointer to a union type, we can cast it to any of the types of
   * the fields in the union before dereferencing, to get the values out. */

  union foo *ptr = &x;

  printf("\nx.a = %d (retrieved by pointer)\n", *(int*)ptr);

  x.c = 'Q';
  printf("x.c = %c (retrieved by pointer)\n", *(char*)ptr);
}
