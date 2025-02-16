// very simple usage, just creating a type alias
typedef int burger;



/* Renaming structs ===========================================================
 *
 * In practice, typedef is often used to rename structs so that we don't have
 * to type the word struct every time we want to use the struct.*/

struct animal {
  char *name;
  int  leg_count, speed;
};

//      original name new name
//      |-----------| |----|
typedef struct animal animal;


// or, more concise:

//       original
//      |---------|
typedef struct book {
  char *title;
  int  page_count;
} book; // <- new


// or, even more concise:

typedef struct {
  float x, y;
} point; // <- name


int main(void) {
  burger x    = 5; // stunning
  animal cat  = {.name="Cat", .leg_count=4, .speed=20};
  book   lotr = {.title="Lord of the Rings", .page_count=1214};
  point  here = {.x=46.947, .y=7.436};
}
