#include <stdio.h>
#include <stdlib.h>

int main(void) {
  /* Numeric value to string ==================================================
   *
   * To convert a numeric to a string, we use the sprintf() or snprintf()
   * functions which work like printf() but they print to a string.
   *
   * Both functions take a char[] as the destination, a format specifer and an
   * input numeric. The snprintf() function takes an additional maxlen
   * parameter, which specifies the maximal amount of characters (including
   * NUL-terminator) which will be written. 
   * This is preferred as it doesn't risk overflowing the destination array. */

  char s[10];
  float f = 3.14159;

  snprintf(s, 10, "%f", f);
  printf("%s\n", s);



  /* String to numeric value ==================================================
   *
   * In stdlib.h there are the following functions allowing to safely convert
   * strings to other types:
   *
   * strtol       String to long int
   * strtoll      String to long long int
   * strtoul      String to unsigned long int
   * strtoull     String to unsigned long long int
   * strtof       String to float
   * strtod       String to double
   * strtold      String to long double
   *
   * These all take as inputs:
   *  - the string to convert
   *
   *  - a pointer to a string (thus a char**) for error handling:
   *      If an error occurs this pointer will be changed to point to the
   *      character where the error occurred.
   *      We can pass NULL if we don't care about errors.
   *
   *  - the radix of the number represented in the string. */

  char *a = "3490";
  unsigned long int x = strtoul(a, NULL, 10);
  printf("x = %lu\n", x);


  char *b = "10011";
  unsigned long int y = strtoul(b, NULL, 2); // binary
  printf("y = %lu\n", y);


  char *c = "42abc37"; // faulty numeric
  char *error;
  unsigned long int z = strtoul(c, &error, 10); // &error => char**
  printf("z = %lu\n", z);
  printf("error = %c\n", *error);


  // If nothing goes wrong *error will point to the NUL-terminator
  char *d = "4237"; // faulty numeric
  char *e;
  unsigned long int g = strtoul(d, &e, 10); // &error => char**
  printf("g = %lu\n", g);
  printf("e = %c\n", *e);
}
