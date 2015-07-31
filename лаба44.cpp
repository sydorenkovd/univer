#include <stdio.h>
 int strcmp(const char *a, const char *b) {
  for (; a != '\0' && b != '\0'; ++a, ++b)
    if (*a != *b)
      return *a - *b;
  return 0;
}
 int main(void) {
  printf("%d\n", strcmp("abcd", "abcd"));
  printf("%d\n", strcmp("abcd", "abc"));
  printf("%d\n", strcmp("abc", "abcd"));
  printf("%d\n", strcmp("abce", "abcd"));
  printf("%d\n", strcmp("abcd", "abce"));
  return 0;}

