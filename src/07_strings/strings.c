#include <stdio.h>

int main(void) {
  /* Strings ==================================================================
   *
   * In C, strings barely exist, they are in fact just pointers lmao gottem
   *
   * Let's start with string literals and string variables.
   * String literals are just character sequences in double quotes.
   *
   * String variables are actually char-pointers (char*), meaning a string
   * variable is just a pointer to the first character in that string, much
   * like arrays. */

  printf("Hello, World!\n"); // string literal

  char *s = "apples";         // pointer to "f"
  printf("%s\n", s);



  /* Strings as arrays ========================================================
   *
   * Another option to represent strings is as an array. This is equivalent to
   * the above char* usage.*/

  char t[] = "bananas";

  for (int i = 0; i < 7; i++) {
    printf("%c", t[i]); // %c is the format specifier for characters
  }
  printf("\n");


  /* Once again we see a similarity between arrays and pointers, as the above
   * for loop also works with a normal char pointer.
   * Thus we can use array notation with pointers. */

  char *u = "oranges";

  for (int i = 0; i < 7; i++) {
    printf("%c", u[i]); // %c is the format specifier for characters
  }
  printf("\n");


  /* The subtle difference between these two is the fact that strings defined
   * as char pointers i.e. as literals are immutable, as they are stored
   * somewhere in the heap. Strings defined as an array are mutable.*/

  t[0] = 'z'; // no problemo
  printf("%s\n", t);

  #ifdef ERROR
  s[0] = 'z'; // yes problemo (segmentation fault)
  #endif
}
