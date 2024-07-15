#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// -----------------------------------------------------------------------------
// Structs
// -----------------------------------------------------------------------------

// flags_t - struct has the flags for cat
typedef struct {
  bool b;
  bool e;
  bool n;
  bool s;
  bool t;
  bool v;
} flags_t;

// -----------------------------------------------------------------------------
// Functions
// -----------------------------------------------------------------------------

// catParserFlags - parse flags
bool parserFlags(int argc, char **argv, flags_t *flags);
// catFile - function opening file and output
void catFile(FILE *file, flags_t flags, int *count, int *count_old_n);
