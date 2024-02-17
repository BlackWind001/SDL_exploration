#include <stdio.h>
#include "utils.h"

int str_len (char *string) {
  char *end = string;

  if (end == NULL) {
    return 0;
  }

  while (*end != '\0') {
    end++;
  }

  return end - string;
}


/**
 * Unsafe concatenation of 2 strings.
*/
char* str_concat (char *str1, char *str2) {
  int len1 = str_len(str1), len2 = str_len(str2);
  char *str1_end = str1 + len1;

  for (int i = 0; i < len2; i++) {
    *str1_end = str2[i];
    str1_end++;
  }

  *str1_end = '\0';

  return str1;
}

char* str_reverse (char *string) {

  if (string == NULL) {
    return string;
  }

  int len = str_len(string);
  char *start = string, *end = start + len - 1;
  char temp;
  int counter = 0;

  while (start < end) {
    temp = *start;
    *start = *end;
    *end = temp;

    start++;
    end--;
  }

  return string;
  
}

/**
 * Expect buffer to have atleast 33 bytes of space.
*/
char* uint32_to_bit_string (char *buffer, unsigned long value) {
  int size = sizeof(value), temp;

  for (int i = 0; i < size*8; i++) {
    str_concat(buffer, value >> 1 ? "1" : "0");
    value = value >> 1;
  }

  return str_reverse(buffer);
}