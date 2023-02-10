#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main()
{
    // this does the same as running grep fork.c < counts

    pid_t fork_rv = fork();
    if (fork_rv == -1)
    {
        perror("fork");
        exit(1);
    }
   
    if (fork_rv == 0)
    {
        // in the child
        
        // close stdout
        if (close(STDIN_FILENO) == -1)
        {
            perror("close");
            exit(1);
        }

        // open "counts", which will open with fd==0
        if (open("counts", O_RDONLY) < 0)
        {
            perror("open");
            exit(1);
        }

        // grep has no idea its STDIN has been replaced
        char *prog[] = {"grep", "fork.c", NULL};
        execvp(prog[0], prog);
        perror("exec");
        exit(1);
    }

    // in the parent
    pid_t wait_rv = wait(NULL);
    if (wait_rv == -1)
    {
        perror("wait");
        exit(0);
    }

    return 0;
}
