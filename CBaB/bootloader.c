#include <stdio.h>
#include "bios.h"
#include "verbose.h"

// program starts by reading the contents of the BIOS.C file
int main() {
  verbose("Starting File [BIOS.C]");
  bios();
}

