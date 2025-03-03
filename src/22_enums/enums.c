#include <stdio.h>

/* Enumerated types (enums) ====================================================
 *
 * Another way of giving constant integer values a name are enums.
 * Enums can only be integer types, and they are usually used in combination
 * with a switch statement.
 *
 * The values of an enum are automatically numbered from 0 upwards, unless
 * explicitly overridden. */

enum {
  SHEEP, // value 0
  WHEAT, // value 1
  WOOD,  // value 2
  BRICK, // value 3
  ORE,   // value 4
};


/* Numbering happens kind of automatically, if an explicit value is specified,
 * but then one is left out, it will just take the next higher number. */

enum {
  A,      // value 0
  B,      // value 1
  G = 6,  // value 6 (duh)
  H,      // value 7 (wow)
  I,      // value 8
  X = 23, // value 23
  Y,      // value 24
  Z,      // value 25
};


/* Enums are actually types, just like a struct. We can give them a tag name
 * so that we can declare variables of that type. This really helps with
 * clarity, when integers need to be passed around, but these integers should
 * convey some sort of information.
 *
 * We could of course also use typdef in a similar manner to how we used it
 * with structs. */

enum urgency {
  LOW,     // = 0
  HIGH,    // = 1
  CRITICAL // = 2
};


void print_message(char *message, enum urgency urg) {
  char *prefix;
  switch (urg) {
    case LOW:      prefix = "INFO";    break;
    case HIGH:     prefix = "WARNING"; break;
    case CRITICAL: prefix = "ERROR";   break;
  };

  printf("%s: %s\n", prefix, message);
}


int main(void) {
  printf("%d %d %d\n", SHEEP, WOOD, BRICK); // 0 2 3
  printf("%d %d %d %d\n", B, G, I, Y);      // 1 6 8 24

  print_message("Hello, World!", LOW);
  print_message("help!", CRITICAL);
}
