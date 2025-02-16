#include <stdio.h>

#define COUNT 7

int main(void) {
  /* Binary file IO ===========================================================
   *
   * Binary files work very similarly to text files, except the IO subsystem
   * just gives us raw bytes. To use binary mode, we have to add a 'b' to the
   * mode passed to fopen, thus 'w' becomes 'wb' and 'r' becomes 'rb'.
   *
   * As bytes can be NUL, we usually use fread() and fwrite() to interact with
   * byte streams.
   *
   * Let's write and read a sequence of bytes. */

  FILE *fp_write = fopen("files/output.bin", "wb");
  unsigned char bytes[COUNT] = {5, 37, 0, 101, 255, 42, 65};

  /* fwrite() takes the following arguments:
   *  - pointer to the data to write
   *  - size of each 'piece' of data
   *  - count of each 'piece' of data
   *  - a FILE*
   *
   * It's like saying, "we have items that are this big and we have that many
   * of them." */

  fwrite(bytes, sizeof(char), COUNT, fp_write);

  fclose(fp_write);
  printf("Successfully wrote to files/output.bin\n");


  FILE *fp_read = fopen("files/output.bin", "rb");
  unsigned char c;

  /* fread() returns the number of bytes read, or 0 on EOF, thus we can read
   * one at a time into a character while the return value isn't 0. */

  while (fread(&c, sizeof(char), 1, fp_read) > 0)
    printf("%d ", c);

  printf("\n");
  fclose(fp_read);


  // WARN: binary data should always be serialized when written to a file.
}
