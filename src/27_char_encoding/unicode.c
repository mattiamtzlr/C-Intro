#include <stdio.h>
#include <string.h>

/* Unicode =====================================================================
 *
 * In the Unicode encoding standard, every symbol has a code-point, effectively
 * a unique identifier for that symbol.
 *
 * A symbol's encoding is how we represent that symbol in memory, usually the
 * values of a sequence of bytes.
 * Some known encodings are:
 *
 *   UTF-8:  byte-oriented encoding that uses a variable number of bytes
 *           per character. Usually the one to use, as it is backwards
 *           compatible with ASCII.
 *
 *   UTF-16: 16-bits per character encoding (can be variable)
 *
 *   UTF-16: 32-bits per character encoding
 *
 * We can use Unicode code points in string literals using the \u and \U escape
 * flags. These must always be padded with leading zeroes to 4 and 8 digits. */

char *s = "\u20aC 1.20";
char *t = "\U0001d4e1";



int main(void) {
  printf("%s | %s\n", s, t);

  /* Dangers of multi-byte characters ==========================================
   *
   * When using multi-byte characters, we have to be carful with functions
   * operating on a byte level, such as strlen(), strchr(), toupper() and so on,
   * as they might produce incorrect output. */

  printf("strlen('%s') = %lu\n", s, strlen(s));
}
