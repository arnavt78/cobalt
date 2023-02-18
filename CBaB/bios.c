#include <stdio.h>
int main() {
  printf("\e[1;1H\e[2J"); //Clears Screen.
  char os[10] = "COBALT\n"; //Opearting System Name, Maximum of 10 characters.
  int ver = 4; //Operating System Build, Maximum of 5 characters.
  printf("%s", os); //Prints OS Name
  printf("%s", "BUILD: "); //Prints Build
  fflush(stdout); //Flushes
  printf("%i", ver); //Prints Version directly after Build
  fflush(stdout); //Flushes
  sleep(3); //Waits 3 Seconds.
  printf("\e[1;1H\e[2J"); //Clears Screen.
  int betabuild = -1; //Null
  switch (ver) { //Simpler Version Management
    case 100: //If the Version is 100,
      betabuild = 0; //Set Betabuild to False
      printf("%s", os);
      break; //Exits
    default: //If Version is NOT 100,
      betabuild = 1; //Set Betabuild to True
      printf("%s", os); //Prints OS
      printf("[!] The Current Version of Cobalt is in beta. If available, please upgrade to a newer version. [!]\n"); //Prints the beta disclaimer
      break; //Exits
  }
  sleep(3);
  const betastatus = betabuild;
  switch (betastatus) { //Checks to see if the previous check worked properly, and checks if the variable 'BETABUILD' is 0 or 1, and not -1
    case -1: //If BetaBuild is -1 (Should not be -1, if it is prints an Error.)
      printf("\e[1;1H\e[2J"); //Clears SCreen
      printf("%s", os); //Prints OS Name
      char errortype[5] = "A.A"; //Creates the Error Type
      printf("The OS has Experienced a fatal error which has caused it to crash.\nTry Restarting. If the Error Persists, post this issue on Github.");
      printf("\nSTOPCODE: A.A {BETABUILD_NOT_POSITIVE_OR_ZERO}\n"); //Crashes, Gives information on Crash
      return 1;
  }
  printf("\n>> Betabuild has been changed from -1 [Null] to ");
  switch (betastatus) {
    case 0:
      printf("0. {FALSE}\n");
    case 1:
      printf("1. {TRUE}\n");
  }
}