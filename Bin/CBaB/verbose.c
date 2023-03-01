#include <stdio.h>
#include <string.h>
#include "verbose.h"

// This file contains the code to make the verbose function work
void verbose(char message[], int variable) {
  if (variable == 1) {
    //char message_str[75];
    //sprintf(message_str, "%d", message);
    char output[100]; strcpy (output, message);
    printf("\n {>} ");
    printf(output);
    printf("\n");
  }
}
