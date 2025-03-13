#include <stdarg.h>
#include <stdio.h>

/* Variadic functions ==========================================================
 *
 * Variadic means that a function can take an arbitrary number of arguments, in
 * contrast to regular functions which take a specific number of arguments.
 *
 * One example of these is printf, or any function which format specifier
 * arguments.
 *
 * Variadic functions always need at least one argument. The variadic part is
 * declared using an ellipsis symbol. To access the variable argument list, we
 * use a special variable of type va_list. Then we call va_start)(), process
 * each argument with va_arg() and finally wrap everything up with va_end(). */

/* add `count` arguments passed after `count` */
int add(int count, ...) {
  int sum = 0;

  /* contains our variable arguments */
  va_list va;

  /* use arguments after `count` */
  va_start(va, count);

  for (int i = 0; i < count; i++) {
    /* get the next int in `va` */
    int n = va_arg(va, int);
    sum += n;
  }

  va_end(va);
  return sum;
}


int main(void) {
  printf("%d\n", add(5, 7, 1, 22, -10, 4)); // 24
  printf("%d\n", add(2, 22, 20));           // 42
  return 0;
}
