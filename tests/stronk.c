#include <stdio.h>
#include <string.h>

int main() {
  char myStr[] = "/bin/ls /bin/ls /bin/ls /bin/ls";
  char *myPtr = strtok(myStr, " ");
  while (myPtr != NULL) {
    printf("%s\n", myPtr);
    myPtr = strtok(NULL, " ");
  }
  return 0;
}
