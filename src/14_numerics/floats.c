#include <stdio.h>
#include <float.h>

int main(void) {
  /* Floats: double and long double ===========================================
   *
   * Remember, significand / mantissa, exponent, sign, yada yada.
   *
   * We can increase the precision of float by using double or even long
   * double. The sizes are given below. */

  printf("FLT_RADIX = %d\n\n", FLT_RADIX); // exponent of FP format
  printf("Precisions:\n  float = %zu, double = %zu, long double = %zu\n\n",
         sizeof(float), sizeof(double), sizeof(long double));



  /* Minimum guaranteed precision =============================================
   *
   * We can use the following macros to see the amount of decimal digits we can
   * store in a float, double or long double and be guaranteed to get back the
   * same number. */

  printf(
    "# decimal digits:\n  float = %d, double = %d, long double = %d\n\n",
    FLT_DIG, DBL_DIG, LDBL_DIG
  );



  /* Float constants ==========================================================
   *
   * By default a float constant is actually of type double. We can force the
   * variable to be of type float by appending 'F' or of type long double by
   * appending 'L'.
   * These suffixes are case insensitive.
   *
   * However, the compiler is pretty good at doing numeric conversions, so it
   * doesn't really matter. */

  float x = 3.14f;
  float y = 3.14;
  float z = 3.14L;



  // We can also define numbers in scientific notation:
  double a = 1.72e-2;        // 0.0172
  printf("%g = %.2e\n", a, a); // format modifier: e
}
