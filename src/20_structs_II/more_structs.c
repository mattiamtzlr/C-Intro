#include <stdio.h>
#include <stddef.h>

struct foo {
  int a;
  char b;
  int c;
  char d;
};



/* Bit-fields ==================================================================
 *
 * If we know that we're not going to use all bits of a field, we can limit its
 * size and ask the compiler to pack them together into one value.
 * This is especially useful for very low-level applications or bit-packing.
 *
 * For this, it is usually smart to explicitly declare the fields as unsigned
 * or signed. Also, this only works with adjacent fields. */

struct bar {
  unsigned int a:5; // <-- range: [0, 31]
  unsigned int b:5;
  unsigned int c:3; // <-- range: [0,  7]
  unsigned int d:3;
};

/* This will occupy less memory (see in main) than using 4 unsigned ints
 * normally which would amount to 16 bytes. */


/* We can also have unnamed bit-fields, if we just want to separate two values,
 * for example if we need the top 2 bits and the bottom 1 bit of a byte. */

struct baz {
  unsigned int a:2;
  unsigned int :5;  // <-- unnamed bit-field
  unsigned int b:2;
};



int main(void) {
  /* Padding bytes and offsetof ================================================
   *
   * The C compiler will add padding bytes within or after a struct to optimize
   * performance. Thus we cannot expect adjacent fields to be adjacent in
   * memory, which is something that can be observed for example in linked_list.c
   *
   * Another way of seeing this is checking manually. */

  printf("sizeof(int)\n + sizeof(char)\n + sizeof(int)\n + sizeof(char) = %zu",
         sizeof(int) + sizeof(char) + sizeof(int) + sizeof(char));
  printf("\n\nsizeof(struct foo) = %zu\n\n", sizeof(struct foo));

  /* To see the padding directly, we can use the offsetof function defined
   * in stddef.h
   * The below code shows us that each field occupies 4 bytes of memory, even
   * though char only needs 1.*/

  printf("offset of a: %zu\n", offsetof(struct foo, a)); // 0
  printf("offset of b: %zu\n", offsetof(struct foo, b)); // 4
  printf("offset of c: %zu\n", offsetof(struct foo, c)); // 8
  printf("offset of d: %zu\n", offsetof(struct foo, d)); // 12


  /* Getting the size of the bit-field struct bar */
  printf("\nsizeof(struct bar) = %zuB instead of 16B\n", sizeof(struct bar));

  /* Getting the size of the bit-field struct baz */
  printf("sizeof(struct baz) = %zuB instead of 12B\n", sizeof(struct baz));
}
