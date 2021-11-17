#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <time.h>

int main() {
  srand(time(NULL));

  printf("Start ...\n");

  int child1 = fork();
  int child2;

  if(child1) {
    rand();
    child2 = fork();
  }

  if(child1 && child2) {
    int status;
    wait(&status);
    printf("Parent process complete.\n");
  }
  else {
    printf("Child PID: %d\n", getpid());

    int t = (rand() % 4) + 2;
    sleep(t);
    printf("Child process complete. ");
    printf("Child PID %d was asleep for %d seconds.\n", getpid(), t);
    return t;
  }

  return 0;
}
