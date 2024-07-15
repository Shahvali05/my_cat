#include "../include/cat.h"

// -----------------------------------------------------------------------------
// Initialization functions
// -----------------------------------------------------------------------------

// help function for catFile
void keyV(int c, flags_t flags);

// -----------------------------------------------------------------------------
// Functions
// -----------------------------------------------------------------------------

// catFile - function opening file and output
void catFile(FILE *file, flags_t flags, int *count, int *count_old_n) {
  int c;
  while ((c = fgetc(file)) != EOF) {
    if (*count_old_n > 0) {
      if (flags.s && c == '\n' && *count_old_n > 1) continue;
      bool is_print_count = false;
      if (flags.b) {
        if (c != '\n') is_print_count = true;
      } else if (flags.n)
        is_print_count = true;
      if (is_print_count) printf("%6d\t", (*count)++);
    }
    if (flags.v) {
      keyV(c, flags);
    } else {
      if (c == '\n' && flags.e) printf("$");
      if (c == '\t' && flags.t)
        printf("^I");
      else
        printf("%c", c);
    }
    if (c == '\n')
      (*count_old_n)++;
    else
      *count_old_n = 0;
  }
}

// keyV - help function for catFile
void keyV(int c, flags_t flags) {
  if (c >= 32) {
    if (c < 127)
      printf("%c", c);
    else if (c == 127) {
      printf("^?");
    } else {
      printf("M-");
      if (c >= 128 + 32) {
        if (c < 128 + 127)
          printf("%c", c - 128);
        else {
          printf("^?");
        }
      } else {
        printf("^");
        printf("%c", c - 128 + 64);
      }
    }
  } else if (c == '\t' && !flags.t)
    printf("\t");
  else if (c == '\n') {
    if (flags.e) {
      printf("$");
    }
    printf("\n");
  } else {
    printf("^%c", c + 64);
  }
}
