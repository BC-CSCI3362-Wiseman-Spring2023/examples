#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void pipe_wrap(int *pipe_fds)
{
    if (pipe(pipe_fds) == -1)
    {
        perror("pipe");
        exit(1);
    }
}

pid_t fork_wrap()
{
    pid_t fork_rv = fork();
    if (fork_rv == -1)
    {
        perror("fork");
        exit(1);
    }
    return fork_rv;
}

void close_wrap(int fd)
{
    if (close(fd) == -1)
    {
        perror("close");
        exit(1);
    }
}

int dup_wrap(int fd)
{
    int new_fd = dup(fd);
    if (new_fd == -1)
    {
        perror("dup");
        exit(1);
    }
    return new_fd;
}

int wait_wrap()
{
    pid_t wait_rv = wait(NULL);
    if (wait_rv == -1)
    {
        perror("wait");
        exit(1);
    }
    return wait_rv;
}

int main()
{
    // create a pipe
    int pipe_fds[2];
    pipe_wrap(pipe_fds);

    // create the first child
    pid_t fork_rv = fork_wrap();
    if (fork_rv == 0)
    {
        // in the first child

        // close the read end, since we are going to write here
        close_wrap(pipe_fds[0]);

        // close stdout
        close_wrap(STDOUT_FILENO);

        // dup the write end of the pipe onto stdout
        dup_wrap(pipe_fds[1]);

        // don't need the original pipe fd any more
        close_wrap(pipe_fds[1]);

        // run grep printf fork.c
        char *prog[] = {"grep", "printf", "fork.c", NULL};
        execvp(prog[0], prog);
        perror("exec");
        exit(1);
    }

    // in the parent, make another child
    pid_t fork_rv2 = fork_wrap();
    if (fork_rv2 == 0)
    {
        // in the second child

        // close the write end, since we are going to read here
        close_wrap(pipe_fds[1]);

        // close stdin
        close_wrap(STDIN_FILENO);

        // dup the read end of the pipe onto stdin
        dup_wrap(pipe_fds[0]);

        // don't need the original pipe fd any more
        close_wrap(pipe_fds[0]);

        // run wc -l
        char *prog[] = {"wc", "-l", NULL};
        execvp(prog[0], prog);
        perror("exec");
        exit(1);
    }

    // in the parent, cleanup 
    
    // close the pipe
    close_wrap(pipe_fds[0]);
    close_wrap(pipe_fds[1]);

    // wait on both children
    wait_wrap();
    wait_wrap();

    return 0;
}
