#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

  if (argc != 3) {
    printf("Usage: %s <src> <dst>\n", argv[0]);
    return 1;
  }

  // open source file
  FILE* src = fopen(argv[1], "r");
  if (src == NULL) {
    printf("Error: cannot open file %s\n", argv[1]);
    return 1;
  }

  // open destination file
  FILE* dst = fopen(argv[2], "w");

  // get size
  fseek(src, 0, SEEK_END);
  long src_size = ftell(src);
  fseek(src, 0, SEEK_SET);

  int percents = src_size / 100;

  // copy file, echoing % progress
  int i = 0;
  int c;

  while ((c = fgetc(src)) != EOF) {
    fputc(c, dst);
    if (i % percents == 0) {
      printf("%d%%\n", i / percents);
    }
    i++;
  }
}
