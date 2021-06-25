#include "types.h"
#include "stat.h"
#include "fcntl.h"
#include "user.h"
#include "date.h"

int main(int argc, char *argv[]) 
{
    printf(1, "What system call do you like to test? \n");
    printf(1, "1. test get descendant\n");
    printf(1, "2. test get ancestors\n");

    char buf[1024];
    read(0, buf, 1024);
    if (atoi(buf) == 1)
    {
      char ans[100];
      strcpy(ans, "");

      int child1_pid = fork();
      if (child1_pid != 0){
        printf(1, "Current process id: %d\n", getpid());
        get_ancestors(getpid(), ans, 100);
        printf(1, "children of %d: %s\n", getpid(), ans);
        wait();
      }
    }
    else if (atoi(buf) == 2)
    {
      char ans[100];
      strcpy(ans, "");

      int child1_pid = fork();
      if (child1_pid != 0){
        printf(1, "Current process id: %d\n", getpid());
        get_descendants(1, ans, 100);
        printf(1, "ancestor of 1: %s\n", ans);
        wait();
      }
    }
    exit();
}