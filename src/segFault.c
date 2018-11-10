#include "main.h"
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>


void sighandler(int signum) {
  printf("Process %d got signal %d\n", getpid(), signum);
  while(1) delay(1000);
}
