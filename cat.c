#include "include/cat.h"

int main(int argc, char **argv) {
  // input
  flags_t flags = {0};
  bool err = parserFlags(argc, argv, &flags);

  if (err == false) {
    // logic
    int count = 1;
    int count_old_n = 1;
    for (int i = 1; i < argc; i++) {
      if (argv[i][0] != '-') {
        err = false;
        FILE *file = fopen(argv[i], "r");
        if (file == NULL) {
          err = true;
        } else {
          // output
          catFile(file, flags, &count, &count_old_n);
          fclose(file);
        }
        if (err)
          printf("%s: %s: No such file or directory\n", argv[0], argv[i]);
      }
    }
  } else
    printf("Usage: %s [-benstv] [file ...]\n", argv[0]);

  return 0;
}
