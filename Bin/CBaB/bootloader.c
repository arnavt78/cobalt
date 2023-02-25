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
  printf("1 - Start Up Normally [GUI]\n");
  fflush(stdout);
  printf("2 - Start Up Recovery Environment [CLI]\n");
  fflush(stdout);
  printf("3 - Start Up Recovery Environment [CLI + Verbose]\n");
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
    //gui code resides here
  } else if (strcmp(recset, response) == 0) {
    hasverbose = 0;
    verbose("Starting File [BIOS.C]", hasverbose);
    r = bios(hasverbose);
  } else if (strcmp(verbst, response) == 0) {
    hasverbose = 1;
    verbose("Starting File [BIOS.C]", hasverbose);
    r = bios(hasverbose);
  } else {
    //automatically runs gui code
  }
  if (r == 0) {
    return 0;
  } else {
    printf("\e[1;1H\e[2J");
    main();
  }
}

