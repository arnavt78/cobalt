#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
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

int services(hasverbose) {
  // Here's where all the Application Functions will be stored. Kind of Lonely here right now.
  printf("\n>> Complete.\n");
  int Booted = 1; // True, determines if Cobalt has booted
  verbose("Booted has been declared as 1 [True].", hasverbose);
  // While Cobalt is booted (and has not crashed/been exited), interperet commands
  while (Booted = 1) {
    // Creates a history of the commands that have been recieved
    char command[20];
    gets(command);
    verbose("Gathered Input.", hasverbose);
    // Defining commands
    char EXIT[] = ".exit";
    char EXITR[] = ".exit -r";
    char HELP[] = "help";
    char CWD[] = "cwd";
    char VERENB[] = ".verbose --enable";
    char VERDIS[] = ".verbose --disable";
    char VERADD[] = ".verbose --create";
    char VERBOSE[] = ".verbose";
    char CLEARSCREEN[3];
    CLEARSCREEN = "clr";
    verbose("Declared Keywords for Indexing.", hasverbose);
    if (strcmp(EXIT, command) == 0) {
      verbose("Matched Input with Keyword {EXIT}", hasverbose);
      printf(">> Stopping services...\n");
      verbose("Shutting Down...", hasverbose);
      sleep(3);
      // Here's where all services get stopped. After this line of code.
      verbose("Exited Cobalt with Exit Code 0", hasverbose);
      return 0;

      //Inside this else if is what the HELP command prints to the screen
    } else if (strcmp(HELP, command) == 0) {
      printf("\e[1;1H\e[2J");
      verbose("Matched Input with Keyword {HELP}", hasverbose);
      printf(BLU "Cobalt " RED "HELP\n");
      printf(RESET "\n'.exit' - Ends all Cobalt services and shuts down the OS.");
      printf("\n'help' - View information about all available commands in the recovery environment.");
      printf("\n'cwd' - View the current working Directory.\n");
    } else if (strcmp(CLEAR, command) == 0) {
      printf("\e[1;1H\e[2J");
    } else if (strcmp(EXITR, command) == 0) {
      verbose("Matched Input with Keyword {EXIT}", hasverbose);
      printf(">> Stopping services...\n");
      verbose("Shutting Down...", hasverbose);
      sleep(3);
      // Here's where all services get stopped. After this line of code.
      verbose("Exited Cobalt with Exit Code 1", hasverbose);
      return 1;
      //Inside this else if is what the CWD command prints to the screen
    } else if (strcmp(VERENB, command) == 0) {
      hasverbose = 1;
      verbose("Verbose Messages Enabled.");
    } else if (strcmp(VERDIS, command) == 0) {
      hasverbose = 0;
      verbose("Verbose Messages Disabled.");
    } else if (strcmp(VERADD, command) == 0) {
      char subverbose[20];
      gets(subverbose);
      verbose(subverbose, hasverbose);
    } else if (strcmd(VERBOSE, command) == 0) {
      if (hasverbose = 0) {
        printf("Verbose is", RED "Disabled." RESET);
        printf(YEL "[!] Want to Enable it? Try .verbose --enable! [!]" RESET);
      } else if (hasverbose == 1) {
        printf("Verbose is", GRN "Enabled." RESET)
      }
    } else if (strcmp(CWD, command) == 0) {
      verbose("Matched Input with Keyword {CWD}", hasverbose);
      char cwd[260];
      verbose("Declared Variable 'CWD' with name ", hasverbose);
      if (getcwd(cwd, sizeof(cwd)) != NULL) {
        verbose("Found Current Working Directory. Outputting Result... ", hasverbose);
        printf("Current working directory: %s\n", cwd);

      } else {
        verbose("Error: Could not find Current Working Directory.", hasverbose);
        printf("getcwd() error");
        return 1;
      }
    // Clears Screen
    // Returns an error if any command that is not defined is ran
    } else {
      if (hasverbose == 1) {
        printf("{>} Failed to Match Input with Keyword. {");
        printf(command);
        printf("}\n");
      }
      printf(YEL "[!] Invalid operation. Please try again. [!]\n" RESET); 
  }
}
}
//comment
