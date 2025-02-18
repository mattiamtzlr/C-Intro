#include <stdio.h>
#include <stdlib.h>

/* Reading lines of arbitrary length ==========================================
 *
 * In this example, we'll see how to use realloc to grow a buffer as we need
 * more space, and also how to use it to shrink the buffer to the perfect
 * size after completing the read.
 *
 * This is done by calling fgetc() over and over until a newline is read.
 *
 * Returns a pointer to the read line. */
char *readline(FILE *fp) {
  int offset = 0;
  int bufsize = 4; // starting size, power of two
  int c;           // current char

  char *buf = malloc(bufsize);

  if (buf == NULL)
    return NULL;


  // assign c, then check conditions (comma operator)
  while (c = fgetc(fp), c != '\n' && c != EOF) {
    // check if there is still space (-1 for NUL terminator)
    if (offset == bufsize - 1) {
      bufsize *= 2; // convention: double the buffer, when out of space

      char *new_buf = realloc(buf, bufsize);

      if (new_buf == NULL) {
        free(buf);
        return NULL;
      }

      buf = new_buf; // successful realloc
    }

    buf[offset++] = c; // add byte to buffer
  }


  // no bytes read
  if (c == EOF && offset == 0) {
    free(buf);
    return NULL;
  }


  // shrink to fit actual line length
  if (offset < bufsize - 1) {
    char *new_buf = realloc(buf, offset + 1); // (+1 for NUL terminator)

    if (new_buf != NULL)
      buf = new_buf; // otherwise just keep using buf
  }

  buf[offset] = '\0'; // add NUL terminator
  return buf;
}

int main(void) {
  FILE *fp = fopen("files/lines.txt", "r");
  char *line;

  while ((line = readline(fp)) != NULL) {
    printf("%s\n", line);
    free(line); // free buffer holding line
  }

  fclose(fp);
}
