#include <stdio.h>

// accepts an int-pointer and increments the thing that the pointer points to
void increment(int *p) {
  *p = *p + 1;
}


int main(void) {
  // an int uses 4 bytes of memory
  printf("an int uses %zu bytes of memory\n", sizeof(int));

  /* Pointers =================================================================
   *
   * Generally, "a pointer is a variable that holds an address", i.e. it points
   * or "refers" to the another value which is in at that address in memory.
   *
   * Another analogy is a house and its address, where the address isn't the
   * same as the house itself, but it is a pointer to the house, telling where
   * to find it */

  int i = 10;

  // we use the ampersand symbold & to get the address of a variable
  printf("the value of i is %d\n", i);
  printf("and its address is %p\n", (void*) &i);
  // here we had to type cast the pointer variable to void* - see later


  int j;  // type: int
  int *p; // type: int pointer (int*)

  p = &j; // p now points to j - the address of j is stored in the pointer to j



  /* Dereferencing ============================================================
   *
   * By dereferencing the pointer variable, we can use the original variable.
   * Thus, if we have a variable j and a pointer p, which points to j, then we
   * can use the dereferenced pointer p exactly as if it were j.
   *
   * This is like using the address of a house to go to that house. */

  j  = 10; // modifying j directly
  *p = 20; // modifiy j indirectly through dereferencing (*) the pointer

  printf("j is %d\n", j);  // |
  printf("j is %d\n", *p); // |-> these are equivalent

  // but why?



  /* Passing pointers as arguments ============================================
   *
   * Earlier we saw that every argument passed to a function gets copied into
   * parameters, thus only local copies of the arguments are handled within
   * functions.
   *
   * The same happens with pointers, i.e. if we pass a pointer as an argument
   * to a function, it will be copied, but the variable it points to will stil
   * be the same. Thus, within the function, it can be dereferenced, giving
   * access to the original value in the outer scope. */

  int k  = 10;
  printf("k is %d\n", k);

  // pass the pointer to k to increment (see definition further up)
  increment(&k);
  printf("k is now %d\n", k);

  /* Generally, if we want a function to modify the thing that is passed to it,
   * we have to use a pointer to that thing. */



  /* The NULL pointer =========================================================
   *
   * Any pointer variable can be set to the special value NULL, indicating that
   * this pointer doesn't point to anything.
   *
   * This also means that dereferencing it will probably result in a crash and
   * is generally not memory-safe.
   * It may be used as a flag though.*/

  int *q;
  q = NULL;

  #ifdef ERROR
  *q = 12; // crash or some prohibited memory access (Segmentation fault)
  #endif



  /* Pointer declaration syntax ===============================================
   * The following are all equivalent
   *
   * 1.   int *p;
   *      int q;
   *
   * 2.   int *p, q;
   *
   * 3.   int* p, q;
   *
   * They all declare p as an int-pointer variable, and q as an int. */



  int x = 5;
  int y = 7;

  /* Pointers and const =======================================================
   *
   * The first of the following lines creates a pointer to a constant object,
   * thus the value of the pointed to object cannot be changed. The pointer
   * itself may be redefined.
   *
   * The second line creates a constant pointer to a mutable object, meaning
   * the pointer itself cannot be modified, but the object it points to can. */

  int const *r = &x;

  #ifdef ERROR
  *r = 9;
  #endif

  r = &y;


  int *const s = &x;

  *s = 9;

  #ifdef ERROR
  s = &y;
  #endif

}
