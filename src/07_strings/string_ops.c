#include <stdio.h>
#include <string.h>

int my_strlen(char *s);

int main(void) {
  /* String length ============================================================
   *
   * Getting the length of a string is similarly annoying to getting the length
   * of an array, as a string is really just pointers and C doesn't track the
   * length for us.
   * Luckily, there's a function in <string.h> called strlen() which computes
   * the length of a string in bytes. */

  char *s = "Hello, World!";
  printf("'%s' is %zu bytes long\n", s, strlen(s));

  // be careful with multi-byte characters
  char *t = "🐉"; // this is actually 4 bytes
  printf("'%s' is %zu bytes long\n", t, strlen(t));


  printf("%zu bytes\n", strlen(s));
  printf("%zu bytes\n", strlen(t));



  /* Copying a string =========================================================
   *
   * As strings are char-pointers, copying a string isn't as simple as using
   * assignment operator (=), as that will just create a new pointer pointing
   * to the same string.*/

  char a[] = ":)";   // mutable
  char *b  = a;

  b[1] = '(';        // allowed as the string b points to is mutable
  printf("%s\n", a); // the original is also modified


  /* To actually copy a string, we use the strcpy() (or strncpy) function from
   * <string.h>, which copies a string into another array, which must have
   * enough free space. */

  char c[] = ":)";
  char d[10]; // plenty of room

  strcpy(d, c);      // first param is the dest, second is the src

  d[1] = '(';        // modify the copy
  printf("%s\n", c); // the original is not modified
}



/* String termination =======================================================
 *
 * In C, strings are defined by:
 *   1. a pointer to the first character in the string, and
 *   2. a zero-valued byte (NUL character) somewhere after the pointer, to
 *      mark the end of the string.
 *
 * When defining a string literal, the NUL byte \0 is automatically inserted
 * at the end.
 *
 * This lets us see how the strlen() function works. */
int my_strlen(char *s) {
  int count = 0;

  while (s[count] != '\0') // count up until NUL byte
    count++;

  return count;
}
