#include <stdio.h>
#include <stdlib.h>

/* Self-referential structs ====================================================
 *
 * We can use self-referential structs to build a linked-list type, where
 * every node points to the next node. These nodes all have the same type, so
 * the struct must be self-referential.
 *
 * Here, we can't use anonymous struct, as we need to reference it within the
 * definition, thus before the typedef completes. */

typedef struct node {
  int data;
  struct node *next;
} node;


/* Links a new node at the end of the given linked-list `n` with value `v`. Also
 * returns a pointer to the modified linked-list or NULL on error. */
node *append(node *n, int v) {
  if (n != NULL) {
    if (n->next != NULL)
      return append(n->next, v);

    node res = *n;

    res.next = malloc(sizeof(node));
    if (res.next == NULL)
      return NULL;

    res.next->data = v;

    *n = res;
  }

  return n;
}


int main(void) {
  node *list = malloc(sizeof(node));
  list->data = 42;

  append(list, 37);
  append(list, 101);
  append(list, 19);

  for (node *curr = list; curr != NULL; curr = curr->next) {
    printf("%p: %d\n", curr, curr->data);
  }
}
