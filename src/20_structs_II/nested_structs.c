#include <stdio.h>

#define MAX_PASSENGERS 5

/* Nested structs ==============================================================
 *
 * When we use a struct within another struct, we can use the struct
 * initializer of the outer struct to initialize the inner struct. Take for
 * example the following two structs. */

typedef struct {
  int window_count;
  int o2_level;
} cabin_information;

typedef struct {
  char *manufacturer;
  cabin_information ci;
} spaceship;



/* It gets even crazier if we use arrays. */

typedef struct {
  char *name;
  int age;
} passenger;

typedef struct {
  int line;
  passenger passengers[MAX_PASSENGERS];
} car;



int main(void) {
  spaceship s = {
    .manufacturer = "General Products",
    .ci.window_count = 3, // <-- nested initializer
    .ci.o2_level = 21     // <-- nested initializer
  };

  // which is equivalent to
  spaceship t = {
    .manufacturer = "General Products",
    .ci = {
      .window_count = 3,
      .o2_level = 21
    }
  };


  // check this out
  car c = {
    .line = 107,
    .passengers[0].name = "Alice",
    .passengers[0].age = 22,
    .passengers[MAX_PASSENGERS - 1] = {.name = "Bob", .age = 42}
  };

  for (int i = 0; i < MAX_PASSENGERS; i++) {
    if (c.passengers[i].name != NULL) {
      printf("Passenger %d: '%s', aged %d\n", i,
             c.passengers[i].name, c.passengers[i].age);
    }
  }
}
