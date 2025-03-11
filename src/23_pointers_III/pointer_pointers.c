#include <stdio.h>

int main(void) {
  /* Pointers to pointers ======================================================
   *
   * A pointer can point to another pointer, as all pointers are stored in
   * memory and thus have an address. */

  int x = 4237; // type int
  int *p = &x;  // type int-pointer
  int **q = &p; // type (int-pointer)-pointer

  printf("Variable   Address          Value\n");
  printf("x          %p   %d\n", &x, x);
  printf("p          %p   %p\n", &p, p);
  printf("q          %p   %p\n", &q, q);

  /* This will print (addresses will change of course):
   *
   *   Variable   Address          Value
   *   x          0x7ffc6e0d3d8c   4237
   *   p          0x7ffc6e0d3d80   0x7ffc6e0d3d8c (= address of x)
   *   q          0x7ffc6e0d3d78   0x7ffc6e0d3d80 (= address of p)
   *
   * which nicely shows how the pointers work. */



  /* Pointer pointers and const ================================================
   *
   * When using the const modifier with multiple indirection levels, we have to
   * be careful to keep the level of 'constness' the same. Consider the
   * following code. */


  /* Pointer a is a constant pointer to x i.e. we cannot change where it
   * points to */
  int *const a = &x;

  /* If we try to create a pointer to the constant pointer a as follows, we will
   * get a compiler warning because we are discarding the constness of
   * the pointer a. */
  int **b = &a;

  /* Thus to correctly create a pointer to the constant pointer a, we have to
   * do the following.
   * Read this as "c is a pointer to a const-int-pointer. " */
  int *const *c = &a;

}
