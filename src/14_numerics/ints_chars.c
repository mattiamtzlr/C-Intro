#include <stdio.h>
#include <limits.h>

int main(void) {
  /* Signed and unsigned integers =============================================
   *
   * yeah */

  signed int x = -42; // equivalent to int a = 42;
  unsigned int y = 42;



  /* Characters ===============================================================
   *
   * Behind the scenes, characters are just 1-byte integers. In the beginnings
   * of C, the standard was more relaxed, but nowadays almost all machines use
   * 8 bits per byte. However, chars might still be signed or unsigned
   * depending on the system. */

  char c;          // could be signed or unsigned
  signed char d;   // definitely signed
  unsigned char e; // definitely unsigned

  char a = 'A';
  char z = 'Z';

  printf("A ... ? ... Z = %c\n\n", (int) ((z - a) / 2) + a);



  /* short, long and long long ================================================
   *
   * We can add the prefixes short, long or long long to the int and char types
   * to specify the minimum number of bytes they occupy.
   *
   * In general, short uses 2 bytes, long 4 and long long 8. 
   *
   * The following pairs of lines are equivalent. */

  long long int p;
  long long q;

  short int r;
  short s;


  printf("char:        min = %+20d, max = %+20d\n", CHAR_MIN, CHAR_MAX);
  printf("signed char: min = %+20d, max = %+20d\n", SCHAR_MIN, SCHAR_MAX);
  printf("short:       min = %+20d, max = %+20d\n", SHRT_MIN, SHRT_MAX);
  printf("int:         min = %+20d, max = %+20d\n", INT_MIN, INT_MAX);
  printf("long:        min = %+20ld, max = %+20ld\n", LONG_MIN, LONG_MAX);
  printf("long long:   min = %+20ld, max = %+20ld\n", LLONG_MIN, LLONG_MAX);
}
