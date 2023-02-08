#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

int main()
{
    printf("My pid=%u\n", getpid());

    pid_t fork_rv = fork();
    if (fork_rv == -1)
    {
        perror("fork");
        exit(1);
    }
   
    if (fork_rv == 0)
    {
        // this means we are in the child process
        printf("CHILD: pid=%u\n", getpid());
    }
    else
    {
        // we are in the parent here
        printf("PARENT: pid=%u\n", getpid());
    }

    return 0;
}
