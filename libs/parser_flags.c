#include "../include/cat.h"

// -----------------------------------------------------------------------------
// Initialization functions
// -----------------------------------------------------------------------------

// help functions for parserFlags
void helpForParseLongFlags(int i, flags_t *flags, char **argv, bool *err);
// help functions for parserFlags
void helpForParseShortFlags(int i, flags_t *flags, char **argv, bool *err);

// -----------------------------------------------------------------------------
// Functions
// -----------------------------------------------------------------------------

// parserFlags - parse flags
// returned error code
bool parserFlags(int argc, char **argv, flags_t *flags) {
  bool err = false;
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      if (argv[i][1] == '-') {
        helpForParseLongFlags(i, flags, argv, &err);
      } else {
        helpForParseShortFlags(i, flags, argv, &err);
      }
    }
  }

  return err;
}

// helpForParseLongFlags - parse long flags
// help functions for parserFlags
void helpForParseLongFlags(int i, flags_t *flags, char **argv, bool *err) {
  if (strcmp(argv[i] + 2, "number-nonblank") == 0) {
    flags->b = true;
  } else if (strcmp(argv[i] + 2, "number") == 0) {
    flags->n = true;
  } else if (strcmp(argv[i] + 2, "squeeze-blank") == 0) {
    flags->s = true;
  } else {
    *err = true;
  }
}

// helpForParseShortFlags - parse short flags
// help functions for parserFlags
void helpForParseShortFlags(int i, flags_t *flags, char **argv, bool *err) {
  for (int j = 1; j < (int)strlen(argv[i]); j++) {
    switch (argv[i][j]) {
      case 'b':
        flags->b = true;
        break;
      case 'e':
        flags->e = true;
        flags->v = true;
        break;
      case 'n':
        flags->n = true;
        break;
      case 's':
        flags->s = true;
        break;
      case 't':
        flags->t = true;
        flags->v = true;
        break;
      case 'v':
        flags->v = true;
        break;
      case 'E':
        flags->e = true;
        break;
      case 'T':
        flags->t = true;
        break;
      default:
        *err = true;
        break;
    }
  }
}
