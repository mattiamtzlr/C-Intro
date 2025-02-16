#include <stdio.h>

/* Structs ====================================================================
 *
 * Classes and objects don't exist in C natively, but we can think of structs
 * as a classes with only data members and no methods.
 *
 * A struct conveniently bundles multiple variables into a single one, which
 * is useful for passing varaibles to functions and for organizing data. */


/* Globally define a 'car' struct which in turn creates a new type, whose full
 * name is 'struct car' (!), not just 'car'. */
struct car {
  char  *name;
  float price;
  int   speed;
};



/* Passing structs to functions ===============================================
 *
 * We can either pass the struct itself or a pointer to the struct, depending
 * on whether we want to modify the original struct (then use a pointer) or
 * not. Another reason for passing a pointer is the struct being really large.
 *
 * Let's define two functions, one modifying the struct, thus requiring a
 * pointer to it, the other merely accessing it, meaning a copy of the struct
 * is enough. */

void set_price(struct car *car, float new_price) {
  car->price = new_price;
}

/* When using a pointer, use the -> operator instead of the . operator to
 * access a field of the struct pointed to by the pointer. The above line is
 * equivalent to the uglier and non-idiomatic (*car).price = new_price */


void print_car(struct car car) {
  printf("Car\n");
  printf(" └ Name:           %s\n", car.name);
  printf(" └ Price (USD):    %.2f\n", car.price);
  printf(" └ Top Speed (km): %d\n", car.speed);
}



// returns 1 if c1, c2 are equal and 0 otherwise
int cars_equal(struct car *c1, struct car *c2) {
  return c1->name == c2->name && c1->price == c2->price && c1->speed == c2->speed;
}



int main(void) {
  // declaring a variable of type struct car
  struct car saturn;

  // initializing the fields
  saturn.name =  "Saturn SL/2";
  saturn.price = 15999.99;
  saturn.speed = 175;

  // retrieving the values
  print_car(saturn);


  /* Using an initializer we can make the definition more concise. Any missing
   * fields will be set to the default value 0. */
  struct car delorean = {.speed=999, .name="Delorean DMC-12"};

  set_price(&delorean, 1000000);

  print_car(delorean);



  /* Struct operations ==========================================================
   *
   * Copying / Returning is done by simply assigning one struct to the other.
   * This isn't a deep copy, meaning all fields are copied as-is, including
   * pointers. (see below for an example)
   *
   * Comparison is done by comparing each field one at a time.*/

  struct car a, b;
  b = a; // copy a to b

  printf("%d\n", cars_equal(&saturn, &delorean));
}
