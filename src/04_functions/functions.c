#include <stdio.h>

/* It is useful to think about arguments to functions as being "copied"
 * into the parameters, see further down. */
int plus_one(int n)
{
  return n + 1;
}


// takes no arguments and returns nothing
void hello(void)
{
  printf("Hello, World!\n");
}


/* Generally, arguments are passed by value, meaning that they are evaluated
 * and then substituted as a copy into the parameters.
 * This means that the following function only modifies the local parameter 'a'
 * and not the actual argument passed to it.*/
void increment(int a)
{
  a++;
}


/* This defines a function prototype, which is a way to tell the compiler that
 * a function with this signature will be used later, but its definition might be
 * after the call or even in a different file.
 * See below the main function for the actual definition.*/
int foo(void);


// the main function
int main(void)
{
  int i = 10, j;
  j = plus_one(i);
  printf("j = %d\n", j);

  hello();

  i = 10;
  increment(i);
  /* Prints 10, as i wasn't modified, only the copy passed to increment
   * which was copied into a. */
  printf("i = %d\n", i);

  /* foo can be called here, even though it hasn't been defined yet,
   * thanks to the prototype. */
  int f = foo();
  printf("f = %d\n", f);
}


// actual function definition of foo, corresponding to the prototype above.
int foo(void)
{
  return 42;
}
