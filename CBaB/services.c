#include <stdio.h>
#include <string.h>
int services() {
  //Here's where all the Application Functions will be stored. Kind of Lonely here right now.
  printf("\n>> Complete.\n");
  int Booted = 1; //True
  while (Booted = 1) {
    char command[7];
    gets(command);
    char EXIT[] = "$EXIT";
    if (strcmp(EXIT,command) == 0) {
      printf(">> Ending Services...\n");
      sleep(3);
      // Here's where all services get stopped. After this line of code.
      return 0;
    }
    else {
      printf("[!] Invalid Operation [!]\n");
    }
  }
}