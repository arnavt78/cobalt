#include <stdio.h>
#include "services.h"
#include "verbose.h"

//colors for text
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define BOLD "\e[1m"
#define RESET "\x1B[0m"


int bios(hasverbose) {
  verbose("Defined Colors.", hasverbose);
  int delay = 3; // The time to wait on the sleep() functions
  printf("\e[1;1H\e[2J");             // Clears Screen.
  char os[25] = BLU "COBALT\n" RESET; // Opearting System Name, Maximum of 10 characters.
  verbose("Classified OS Name", hasverbose);
  int ver = 20;                        // Operating System Build, Maximum of 5 characters.
  verbose("Classified OS Data", hasverbose);
  printf("%s", os);        // Prints OS Name
  printf("%s", "BUILD: "); // Prints Build
  fflush(stdout);          // Flushes
  printf("%i", ver);       // Prints Version directly after Build
  fflush(stdout);          // Flushes
  verbose("Completed 3 Prints and 2 Flushes.", hasverbose);
  sleep(delay); // Waits 3 Seconds.
  printf("\e[1;1H\e[2J"); // Clears Screen.
  int betabuild = -1;     // Null
  delay = 1;
  verbose("Betabuild has been declared as -1 [Null].", hasverbose);
  switch (ver) {                // Simpler Version Management
  case 100:        // If the Version is 100,
    verbose("Betabuild has been changed. [-1 --> 0]", hasverbose);
    betabuild = 0; // Set Betabuild to False
    printf("%s", os);
    break;                                                                                                                                  // Exits
  default:                                                                                                                                  // If Version is NOT 100,
    betabuild = 1;
    verbose("Betabuild has been changed. [-1 --> 1]", hasverbose);                                                                                                                          // Set Betabuild to True
    printf("%s", os);
    verbose("Current Build has been marked as beta. Opening Balloon...", hasverbose);                                                                                                                       // Prints OS
    printf(YEL  "[!] You are currently running a beta build of Cobalt. Please upgrade to a newer version as soon as possible. [!]\n" RESET); // Prints the beta disclaimer
    break;                                                                                                                                  // Exits
  }

  sleep(delay);
  verbose("Checking to see if Betabuild was changed successfully...", hasverbose);
  const betastatus = betabuild;
  switch (betastatus) { // Checks to see if the previous check worked properly, and checks if the variable 'BETABUILD' is 0 or 1, and not -1
  case -1:
    verbose("Betabuild was not changed.", hasverbose);   // If BetaBuild is -1 (Should not be -1, if it is prints an Error.)
    printf("\e[1;1H\e[2J");    // Clears SCreen
    printf("%s", os);          // Prints OS Name
    char errortype[5] = "A.A"; // Creates the Error Type
    printf(RED "A fatal error has occurred which has caused Cobalt to crash.\nCopy down the error code and then try restarting. If the problem persists, try contacting the developers of Cobalt.");
    printf(RED "\nSTOP: A.A [INVALID_BETA_STATUS]\n" RESET); // Crashes, Gives information on Crash
    return 1;
  } // I'm gonna release Version 4 [The Previous Code] that I made.

  printf("\n>> Betabuild has been changed from -1 [Null] to ");

  // controls weather the user is in a beta version or not(?)
  switch (betastatus) {
  case 0:
    printf("0 [False].\n");
  case 1:
    printf("1 [True].\n");
  }
  verbose("Check completed. [Successful]", hasverbose);
  printf("\n>> Starting Services... ");
  sleep(delay);
  int service_result = services(hasverbose);
  if (service_result == 0) {
    return 0;
  } else {
    return 1;
  }
}
