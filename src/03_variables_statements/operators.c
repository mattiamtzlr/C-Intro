#include <stdio.h>

int main(void)
{
  int i = 10;

  /* There are shorthand variants of most common operators to reassign a value
   * with the result of an operation on it */
  i += 3; // i = 13
  i -= 8; // i = 5
  i *= 9; // i = 45
  i /= 2; // i = 22
  i %= 5; // i = 2

  printf("i = %d\n", i);

  // There is also a ternary operator:
  char *j = i % 2 == 0 ? "even" : "odd";
  printf("i is %s\n", j);

  int x;
  int y;
  /* pre-increment and -decrement: */
  x = 10;
  --x;          // decrements x to 9
  ++x;          // increments x to 10
  y = 5 + ++x;  // first increment x by 1 to 11 then calculate y = 5 + x = 16
  printf("x = %d, y = %d\n", x, y);

  /* post-increment and -decrement: */
  x = 10;
  x--;          // decrements x to 9
  x++;          // increments x to 10
  y = 5 + x++;  // first calculate y = 5 + x = 15 then increment x by 1 to 11
  printf("x = %d, y = %d\n", x, y);

  /* The comma operator separates expressions and runs them left by right as a
   * single expression. This means that the final value of the expression is
   * the rightmost one.*/
  x = (1, 2, 3); // equivalent to x = 3

  // The comma can also be used to have multiple iterators in a for loop:
  int a;
  int b;
  for (a = 0, b = 4; a < 5; a++, b--) {
    printf("a=%d, b=%d\n", a, b);
  }

  /* The 'sizeof' operator returns the size (in bytes) in memory of a variable or
   * data type. It returns a value of type size_t, which is an unsigned integer,
   * often used as a counter.
   * The format specifier of size_t is %zu (positive), or %zd (negative) */

  int c = 999;
  printf("sizeof c = 999: %zu\n", sizeof c);
  printf("sizeof 2 + 7: %zu\n", sizeof(2 + 7));
  printf("sizeof 3.14: %zu\n", sizeof 3.14);

  // We can also take the size of a type (has to be put in parentheses)
  printf("sizeof int: %zu\n", sizeof(int));
  printf("sizeof char: %zu\n", sizeof(char));

  /* Important to note is that sizeof is a compile-time operation, meaning the
   * result of the expression is determined at compile-time not at runtime. */
}
