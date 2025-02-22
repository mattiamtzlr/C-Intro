#include <stdio.h>
#include <math.h>

double f1(double x) { return x * x; }
double f2(double x) { return exp(x); }
double f3(double x) { return sqrt(x); }

/* Define Function as a pointer to a function taking a double and returning
 * a double. */
typedef double (*Function)(double);

int main(void) {
  int rep;
  Function choice; // equivalent to double (*choice)(double)

  do {
    printf("Which function do you want to run? [1-3]: ");
    scanf("%d", &rep);
  } while (rep < 1 || rep > 3);

  switch (rep) {
    case 1: choice = f1; break;
    case 2: choice = f2; break;
    case 3: choice = f3; break;
  }

  double x;
  printf("Enter a value x > 0 to pass to the function: ");
  scanf("%lf", &x);

  printf("The result of f%d(%g) is %g\n", rep, x, choice(x));
}
