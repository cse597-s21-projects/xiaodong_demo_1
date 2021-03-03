#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main (int argc,char **argv) {
  void *non_int;
  int k;
  char private_password[10] = "0123456789";

  if (argc == 2) {
    if (strlen(argv[1]) != 10) {
      printf("Incorrect password.\n");
      return 0;
    }
    for (int i=0; i<10; i++) {
      k = argv[1][i];
      usleep(100000); // simulate the computation
      if (k != private_password[i]) {
        printf("Incorrect password.\n");
        return 0;
      }
    }
  }

  printf("Correct password.\n");
  return 0;
}
