#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <locale.h>
#include <wchar.h>

/* Different character types ===================================================
 *
 * The standard 'char' type is actually a multi-byte character, even though
 * it is mainly used for single-byte characters. It could take up to MB_LEN_MAX
 * (defined in <limits.h>) bytes.
 *
 * All characters that aren't multi-byte characters are known as wide
 * characters, which are single values, that can uniquely represent any
 * character in the current locale.
 *
 * To use wide characters, we use the `wchar_t` type defined in <wchar.h> and we
 * prefix strings or character literals with an 'L'. They use the format
 * specifier %ls and %lc respectively. */

wchar_t *s = L"Hello, World!";
wchar_t c = L'B';



int main(void) {
  printf("%d\n", MB_LEN_MAX);
  printf("%ls | %lc\n", s, c);

  /* Conversion functions ======================================================
   *
   * There are some string functions to convert between multibyte (mb) and wide
   * character (wc) characters or strings (s).
   *
   *   mbtowc()     Convert a multibyte character to a wide character.
   *   wctomb()     Convert a wide character to a multibyte character.
   *   mbstowcs()   Convert a multibyte string to a wide string.
   *   wcstombs()   Convert a wide string to a multibyte string.
   *
   * They are all in <stdlib.h>
   * mbstowcs() also returns the number of wide chars, thus the actual character
   * count. */

  /* set locale to environment locale, to make sure that the characters are
   * supported */
  setlocale(LC_ALL, "");

  char *mbs = "\u20ac1.23";
  size_t mbs_len = strlen(mbs);

  /* wide character array to hold the converted string */
  wchar_t wcs[128];
  size_t wcs_len = mbstowcs(wcs, mbs, sizeof wcs);

  printf("multibyte: \"%s\" (%zu bytes)\n", mbs, mbs_len);
  printf("wide char: \"%ls\" (%zu characters)\n", wcs, wcs_len);
}
