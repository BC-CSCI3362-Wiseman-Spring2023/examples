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
    // this does the same as running wc fork.c exec.c wait.c > counts

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
        if (close(STDOUT_FILENO) == -1)
        {
            perror("close");
            exit(1);
        }

        // open "counts", which will open with fd==1
        if (open("counts", O_WRONLY|O_CREAT|O_TRUNC, 0600) < 0)
        {
            perror("open");
            exit(1);
        }

        // wc has no idea its STDOUT has been replaced
        char *prog[] = {"wc", "fork.c", "exec.c", "wait.c", NULL};
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
