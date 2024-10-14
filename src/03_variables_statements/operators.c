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
  for (a = 0, b = 9; a < 10; a++, b--) {
    printf("a=%d, b=%d\n", a, b);
  }
}
