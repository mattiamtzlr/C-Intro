#include <stdio.h>

int main(void)
{
  /* By convention, always put curly braces after a flow control statement, to
   * make it clear what is included and what isn't. */

  int i = 15;
  if (i == 10) {
    printf("==\n");
  }
  else if (i < 10) {
    printf("<\n");
  }
  else {
    printf(">\n");
  }


  /* while:    check condition first, then execute the block.
   * do-while: first to the block, then to the check the condition. will always
   *           execute at least once. */
  i = 0;
  while (i < 10) {
    printf("%d ", i);
    i++;
  }
  printf("\n");

  // will still print 10 once
  do {
    printf("%d ", i);
    i++;
  } while (i < 10);
  printf("\n");


  for (i = 0; i < 10; i++) {
    printf("%d ", i);
  }
  printf("\n");


  /* switch statements are a bit more restricted than other languages. They will
   * evaluate an expression to an integer value and jump to the case which corresponds
   * to that value.
   * Returning from a case is done with break. */

  int goat_count = 20;
  switch (goat_count) {
    case 0:
      printf("You have no goats.\n");
      break;

    case 1:
      printf("You have one single goat.\n");
      break;

    case 20:
      printf("You have many goats.\n");
      break;

    default:
      printf("You sure have goats.\n");
      break;
  }

  /* A switch statement can have fall-through, which is when a break statement is
   * intentionally left out. In that case execution will just continue in the next case. */

  int x = 1;
  switch (x) {
    case 1:
      printf("1 ...\n");

    case 2:
      printf("... and also 2\n");
      break;
  }
}
