#include <stdio.h>
#include "bios.h"
#include "verbose.h"

int verboseisfalse(variable);
int verboseistrue(variable);
// program starts by reading the contents of the BIOS.C file
int main() {
  //Boot Manager
  printf("COBALT BOOT MANAGER\n");
  fflush(stdout);
  sleep(1);
  printf("Normal Startup (1)\n");
  fflush(stdout);
  printf("Fallback Startup (2)\n");
  fflush(stdout);
  printf("Verbose Startup (3)\n");
  fflush(stdout);
  char response[3];
  sleep(3);
  gets(response);
  char guiset[] = "1";
  char recset[] = "2";
  char verbst[] = "3";
  int hasverbose;
  int r;
  if (strcmp(guiset, response) == 0) {
    int status = system("./hi.exe");
    if (status != 0) {
      sleep(3);
      hasverbose = 0;
      verbose("Starting File [BIOS.C]", hasverbose);
      r = bios(hasverbose);
    }
  } else if (strcmp(recset, response) == 0) {
    hasverbose = 0;
    verbose("Starting File [BIOS.C]", hasverbose);
    r = bios(hasverbose);
  } else if (strcmp(verbst, response) == 0) {
    hasverbose = 1;
    verbose("Starting File [BIOS.C]", hasverbose);
    r = bios(hasverbose);
  } else {
    int status = system("./hi.exe");
  }
  if (r == 0) {
    return 0;
  } else if (r == -1) {
    return -1;
  } else {
    printf("\e[1;1H\e[2J");
    main();
  }
}

