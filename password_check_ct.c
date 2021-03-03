#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main (int argc,char **argv) {
  void *non_int;
  int k;
  int result = 1;
  char private_password[10] = "0123456789";

  if (strlen(argv[1]) != 10) {
    return 0;
  }

  if (argc == 2) {
    for (int i=0; i<10; i++) {
      k = private_password[i];
      usleep(100000); // simulate the computation
      result &= (k == argv[1][i]);
    }
  }
  if (result) {
    printf("Correct password.\n");
  }
  else {
    printf("Incorrect password.\n");
  }

  return 0;
}
