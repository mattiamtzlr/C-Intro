#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// This should be bigger, only for demonstration purposes
#define BLOCK_SIZE 2

/* Dynamic arrays =============================================================
 *
 * Using manual memory allocation, we can create a struct behaving similarly
 * to a dynamic array or vector, like ArrayList in Java.
 *
 * In this example, the array will hold doubles. */

typedef double element;

typedef struct {
  size_t size;      // number of elements in the array
  size_t alloc; // currently allocated space
  element *elems;
} vector;


/* Initializes a new vector, writes it to v and also returns it or NULL
 * on error. */
vector *vector_init(vector *v) {
  if (v != NULL) {
    vector result = {.size = 0, .alloc = 0, .elems = NULL};
    result.elems = calloc(BLOCK_SIZE, sizeof(element));

    if (result.elems != NULL)
      result.alloc = BLOCK_SIZE;

    else
      return NULL;

    *v = result;
  }

  return v;
}


// Frees the given vector's content and resetes its other fields
void vector_delete(vector *v) {
  if (v != NULL && v->elems != NULL) {
    free(v->elems);
    v->elems = NULL;
    v->size = 0;
    v->alloc = 0;
  }
}


/* Doubles the allocated space of the vector, also returns the new vector
 * or NULL on error. */
vector *vector_grow(vector *v) {
  if (v != NULL) {
    vector res = *v;
    res.alloc += BLOCK_SIZE;

    if (res.alloc > SIZE_MAX / sizeof(element) ||
        (res.elems = realloc(res.elems, res.alloc * sizeof(element))) == NULL)
      return NULL;

    *v = res;
  }

  return v;
}

/* Adds an element to the end of the vector and returns the new size or zero
 * on error. May reallocate the vector if needed because of the size. */
size_t vector_push(vector *v, element e) {
  if (v != NULL) {
    while (v->size >= v->alloc) {
      if (vector_grow(v) == NULL)
        return 0;
    }

    v->elems[(v->size)++] = e;
    return v->size;
  }

  return 0;
}


int main(void) {
  vector empty = {0, 0, NULL};
  vector *nums = vector_init(&empty);

  vector_push(nums, 3.141);
  vector_push(nums, 2.718);
  vector_push(nums, 1.414);

  for (int i = 0; i < nums->size; i++) {
    printf("nums[%d] = %.3lf\n", i, nums->elems[i]);
  }

  vector_delete(nums);
}
