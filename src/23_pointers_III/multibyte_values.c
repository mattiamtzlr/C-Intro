#include <stdio.h>

/* Multibyte values ============================================================
 *
 * As we know, things usually take up multiple bytes of memory (except chars)
 * and we can tell how many by using sizeof.
 * We can also tell which byte is the first, using the address-of operator &.
 * If we iterate over the bytes of any object, we'll get its object
 * representation, i.e. how it is stored in memory.
 *
 * For this we have to use an unsigned char pointer. This is to make sure, that
 * when increasing the pointer value, we actually increase it by 1 byte and not
 * by sizeof(type).
 * We'll use this to write a version of the memcpy function. */

void *my_memcpy(void *dest, void *src, size_t n) {
  /* cast arguments to unsigned char pointers */
  const unsigned char *s = src;
  unsigned char *d = dest;

  while (n-- > 0)
    /* copy bytes and advance at the same time */
    *(d++) = *(s++);

  /* by convention, return pointer to the destination */
  return dest;
}



/* A consequence of this is that two things with the same object representation
 * in memory are equal. Thus, we can write a function to check whether two
 * objects are equal for a given number of bytes `n`.
 *
 * This function will return zero if the objects are equal in the first `n`
 * bytes and non-zero otherwise. */

size_t memeql(void *obj1, void *obj2, size_t n) {
  const unsigned char *o1 = obj1;
  const unsigned char *o2 = obj2;

  while (n-- > 0)
    if (*(o1++) != *(o2++))
      return 1;

  return 0;
}



/* Size: 1 byte + 4 bytes = 5 bytes
 * Will be padded to 8 bytes, see below. */

typedef struct {
  char a;
  int b;
} foo;



int main(void) {
  int a;
  int x = 42;
  int y = 37;
  int z = 42;

  my_memcpy(&a, &x, sizeof(int));
  printf("a = %d\n", a);


  printf("x and y are %s\n",
         memeql(&x, &y, sizeof(int)) == 0 ? "equal" : "not equal");

  printf("x and z are %s\n",
         memeql(&x, &z, sizeof(int)) == 0 ? "equal" : "not equal");

  putchar('\n');


  /* We can also use this to check how exactly a struct object is stored in
   * memory, thus making eventual offsets visible, as they'll be garbage
   * between the actual values. */

  foo f = {0x41, 0xdeadbeef};
  unsigned char *p = (unsigned char *) &f;

  /* print all bytes in object representation */
  for (size_t i = 0; i < sizeof f; i++)
    printf("%p: %02x\n", p + i, p[i]);

  return 0;
}
