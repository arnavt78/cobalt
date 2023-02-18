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
  if (ver < 100) { //Checks to see if the build is in Beta {Less than 100}
    betabuild = 1; //True
  }
  else { //If this isn't in beta
    betabuild = 0; //False
  }
  printf("COBALT\n"); //Prints Cobalt once again
  if (betabuild = 1) { //Checks to see if the current build is in Beta
    printf("The Current Version of Cobalt that you are using is in Beta. If available, please upgrade to a newer version.\n");
    sleep(3);
  }
}