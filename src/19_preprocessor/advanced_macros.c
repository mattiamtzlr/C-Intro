#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Macros with arguments =======================================================
 *
 * Macros can be set up to take arguments, allowing them to behave similarly to
 * functions. These are mainly used if a function should be platform-dependent
 * or for very short functions. Don't overuse them.
 *
 * When using parametrized macros for math (which is a common usecase), make
 * sure to put parentheses absolutely fucking everywhere, otherwise PEMDAS is
 * coming for your ass. */

/* Square the given number x */
#define SQR(x) ((x) * (x))


/* Find minimum / maximum of given numbers */
#define MIN(x, y) (x) <= (y) ? (x) : (y)
#define MAX(x, y) (x) >= (y) ? (x) : (y)


/* Quadradic formula (minus and plus case) */
#define QUADP(a, b, c) ((-(b) + sqrt((b) * (b) - 4 * (a) * (c))) / (2 * (a)))
#define QUADM(a, b, c) ((-(b) - sqrt((b) * (b) - 4 * (a) * (c))) / (2 * (a)))

/* Combine both for easy printing*/
#define QUAD(a, b, c) QUADP(a, b, c), QUADM(a, b, c)



/* Stringification =============================================================
 *
 * We can turn any argument of a marcor into a string, by preceding it with a #
 * symbol in the definiton. */

#define PRINT_INT_VAL(x) printf("%s = %d\n", #x, x)



/* Multiline macros ============================================================
 *
 * To continue a macro to multiple lines, we use a backslash at the end of the
 * line to escape the newline.
 * Also, we have to wrap the entire macro in a do-while(0) loop to avoid
 * problems with semicolons (what?). */

#define PRINT_RANGE(a, b)       \
  do {                          \
    for (int i = a; i < b; i++) \
      printf("%d ", i);         \
    printf("\n");               \
  } while (0)


/* Using some of the built-in macros, we can define an ASSERT macro, allowing us
 * to assert conditions in our code with an error message for the case where the
 * condition isn't given. */

#define ASSERT(c, m)                                                           \
  do {                                                                         \
    if (!(c)) {                                                                \
      fprintf(stderr,                                                          \
              "\x1b[31m" __FILE__ ":%d:\n  assertion %s failed: %s\n\x1b[0m",  \
              __LINE__, #c, m);                                                \
      exit(1);                                                                 \
    }                                                                          \
  } while (0)



int main(void) {
  /* This will be replaced with ((3 + 4) * (3 + 4)) by the preprocessor. */
  printf("%d\n", SQR(3 + 4));

  printf("%d\n", MIN(37, 42));
  printf("%d\n", MAX(37, 42));

  printf("\n2x² + 10x + 5 = 0\n");
  printf(" └ x ~ %.3f or x ~ %.3f\n\n", QUAD(2, 10, 5));

  int a = 5;
  PRINT_INT_VAL(a);

  PRINT_RANGE(2, 8);

  int x = 30;
  ASSERT(x < 20, "x must be less than or equal to 20");
}
