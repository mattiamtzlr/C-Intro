#include <stdio.h>

#define COUNT 5

int main(void) {
  /* Arrays ===================================================================
   *
   * Arrays in C are basically syntactic sugar, deep down they are just
   * pointers and stuff.
   *
   * Let's start with an example. */

  float f[4]; // fixed-size array of 4 floats

  f[0] = 3.14159;
  f[1] = 1.41421;
  f[2] = 1.61803;
  f[3] = 2.71828;

  for (int i = 0; i < 4; i++) {
    printf("%f\n", f[i]);
  }



  /* The length of an array ===================================================
   *
   * There's not really a direct way to do this, but we can use sizeof, if we
   * in the scope, where the array was defined.
   * If the array is passed to a function however, this doesn't work, as only
   * the pointer to the first element gets passed. */

  int x[12]; // 12 ints

  printf("%zu\n", sizeof x / sizeof(int)); // 48 bytes / 4 bytes/int = 12 ints



  // Array initializers =======================================================

  int a[5] = {22, 37, 42, 101, 15};

  int b[5] = {13, 811, 41}; // {13, 811, 41, 0, 0}

  int c[9] = {0, 11, 22, [5]=55, 66, 77}; // {0, 11, 22, 0, 0, 55, 66, 77, 0}

  int d[COUNT] = {[COUNT-3]=3, 2, 1}; // {0, 0, 3, 2, 1}



  /* Multidimensional Arrays ==================================================
   *
   * An array can have as many dimensions as desired. These are stored in
   * row-major order, meaning, in a 2D array, the first index indicates the row
   * and the second the column. */

  // 2D with 3 rows and 4 columns
  int z[3][4] = {
    {0, 1,  2,  3},
    {4, 5,  6,  7},
    {8, 9, 10, 11},
  };

  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 4; col++) {
      printf("(%d, %d) = %d\n", row, col, z[row][col]);
    }
  }


  // 3x3 identity matrix
  int id[3][3] = {[0][0]=1, [1][1]=1, [2][2]=1};
}
