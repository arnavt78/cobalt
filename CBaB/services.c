#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

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

int services() {
  // Here's where all the Application Functions will be stored. Kind of Lonely here right now.
  printf("\n>> Complete.\n");
  int Booted = 1; // True, determines if Cobalt has booted
  
  // While Cobalt is booted (and has not crashed/been exited), interperet commands
  while (Booted = 1) {
    
    char command[7];
    int history_position = 0;
    int history[100];
    gets(command);
    
    if (sizeof(history) < 100) {
      history[history_position] = command;
    } else {
      int history[100];
    }

    // Defining commands
    char EXIT[] = ".exit";
    char HELP[] = "help";
    char CWD[] = "cwd";
    char HISTORY[] = "history";

    if (strcmp(EXIT, command) == 0) {
      printf(">> Stopping services...\n");
      sleep(3);
      // Here's where all services get stopped. After this line of code.
      return 0;

      //Inside this else if is what the HISTORY command prints to the screen
    } else if (strcmp(HISTORY, command) == 0) { //Doesn't work for some reason
      for (int i = 0; i < sizeof(history)/sizeof(history[0]); i++) {
        printf((char) history_position + ". " + i);
      }

      //Inside this else if is what the HELP command prints to the screen
    } else if (strcmp(HELP, command) == 0) {
      printf("\e[1;1H\e[2J");
      printf(BLU "Cobalt " RED "HELP\n");
      printf(RESET "\n'.exit' - Ends all Cobalt services and shuts down the OS.");
      printf("\n'help' - View information about all available commands in the recovery environment.");

      //Inside this else if is what the CWD command prints to the screen
    } else if (strcmp(CWD, command) == 0) {
      char cwd[PATH_MAX];
      if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working directory: %s\n", cwd);

      } else {
        printf("getcwd() error");
        return 1;
      }

    } else {
      printf(YEL "[!] Invalid operation; please try again. [!]\n" RESET);
    }
  }
}