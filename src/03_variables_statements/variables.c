#include <stdio.h>
#include <stdbool.h>

int main(void)
{
  int i = 2;
  float f = 3.14;
  char *s = "Hello, World!"; // char * (char pointer) is the string type

  printf("%s\ni = %d, f = %f\n", s, i, f); // format string

  /*
   * Booleans are simply represented by 0 meaning false, and non-zero meaning true
   * Thus, 1 is true, so is -37.
   *
   * Using the <stdbool.h> header, we get access to more "traditional" boolean 
   * notations, namely a bool type and true and false values.
  */

  int x = 1;
  if (x) {
    printf("x is true!\n");
  }

  bool y = true;
  bool z = false;
}
