#include <stdio.h>
#include <threads.h>
#include <time.h>

int main(void) {
  /* Escape sequences ==========================================================
   *
   * The most common use for escape sequences is to be able to use symbols
   * within a string or char, which would otherwise act as a keyword or other
   * reserved component of the language.
   * Other very common uses are the newline '\n' and the NUL-terminator '\0'. */

  printf("%c %s %c\n", '\'', "\"", '\\');

  /* Less common escape sequences:
   *   \a  Alert            This makes the terminal make a sound or flash,
   *                        or both!
   *
   *   \b  Backspace        Moves the cursor back a character. Doesn’t delete
   *                        the character.
   *
   *   \f  Formfeed         This moves to the next “page”, but that doesn’t have
   *                        much modern meaning. Usually, this behaves like \v.
   *
   *   \r  Return           Move to the beginning of the same line.
   *
   *   \t  Horizontal tab   Moves to the next horizontal tab stop. Usually, this
   *                        lines up on columns that are multiples of 8
   *
   *   \v  Vertical tab     Moves to the next vertical tab stop. On my machine,
   *                        this moves to the same column on the next line.
   *
   *   \?  Question mark    Sometimes you need this to avoid trigraphs.
   *
   * We can use for example \r and \b to show status updates that appear on the
   * same line on the screen, without scrolling. */

  for (int i = 3; i >= 0; i--) {
    printf("\rT minus \x1B[31m%d\x1B[0m second%s... \b", i, i != 1 ? "s" : "");
    fflush(stdout);
    thrd_sleep(&(struct timespec){.tv_sec = 1}, NULL);
  }
  printf("\rLiftoff!             \n");
}
