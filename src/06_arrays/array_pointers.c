#include <stdio.h>

/* Passing single dimensional arrays to functions ===========================
 *
 * There are multiple different ways of passing an array to a function, among
 * the three listed below, the first being by far the most common.
 *
 * The last doesn't actually enforce anything on the size of the array, only
 * that it must be greater than zero. */

// passing as a pointer to the first element
void foo(int *a, int len);

// same thing, but using array notation
void bar(int a[], int len);

// same thing, but using array notation with size
void baz(int a[5], int len);



/* Changing arrays in functions ===============================================
 *
 * As passing an array to a function is almost equivalent to passing a pointer
 * to a function, we can make changes to a passed array within the function,
 * which will be visible in the caller scope. 
 *
 * Even though we pass a as an int* (int-pointer) type, we can access it using
 * the usual array notation a[i]. This will make more sense later on, when
 * talking about the equivalence of arrays and pointers. */

void double_array(int *a, int len) {
  for (int i = 0; i < len; i++) {
    a[i] *= 2;
  }
}



/* Passing multidimensional arrays to functions ===============================
 *
 * When passing multidimensional arrays to functions, we must specify all
 * dimensions except the first one, as the compiler needs to know, how far to
 * skip in memory for each increment in the first dimension.*/

void print_2d_array(int a[2][3]) {
  for (int row = 0; row < 2; row++) {
    for (int col = 0; col < 3; col++) {
      printf("%d ", a[row][col]);
    }
    printf("\n");
  }
}



int main(void) {
  /* Arrays and pointers ======================================================
   *
   * As briefly mentioned above, a pointer to an array is actually a pointer to
   * the first element of that array, up to the types being different. */

  int a[5] = {11, 22, 33, 44, 55};

  int *p = &a[0];     // p points to the array, or rather, it's first element.
  printf("%d\n", *p); // prints 11 (= a[0])

  int *q = a;         // equivalent to int *q = &a[0], just much nicer
  printf("%d\n", *q);


  double_array(a, 5);
  for (int i = 0; i < 5; i++)
    printf("%d\n", a[i]);


  int x[2][3] = {
    {42,  37, 101},
    {19, 811,  -1},
  };

  print_2d_array(x);
}
