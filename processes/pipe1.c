#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main()
{
    // create a pipe
    int pipe_fds[2];
    if (pipe(pipe_fds) == -1)
    {
        perror("pipe");
        exit(1);
    }

    pid_t fork_rv = fork();
    if (fork_rv == -1)
    {
        perror("fork");
        exit(1);
    }
   
    if (fork_rv == 0)
    {
        // in the child
        // send data back to parent 
        
        // close the read end, since we are going to write here
        if (close(pipe_fds[0]) == -1)
        {
            perror("close");
            exit(1);
        }

        // send the message
        char *msg = "Thank the maker!";
        if (write(pipe_fds[1], msg, strlen(msg)) != strlen(msg))
        {
            perror("write");
            exit(1);
        }

        // close the write end
        if (close(pipe_fds[1]) == -1)
        {
            perror("close");
            exit(1);
        }
        return 0;
    }

    // in the parent
    // get data from the child
    
    // close the write end, since we are going to read here
    if (close(pipe_fds[1]) == -1)
    {
        perror("close");
        exit(1);
    }

    // get the message
    char buf[512];
    int bytes_read = read(pipe_fds[0], buf, 512);
    if (bytes_read < 1)
    {
        perror("read");
        exit(1);
    }
    buf[bytes_read] = '\0';

    printf("In the parent, got: %s\n", buf);

    // close the read end
    if (close(pipe_fds[0]) == -1)
    {
        perror("close");
        exit(1);
    }

    // wait on the child
    pid_t wait_rv = wait(NULL);
    if (wait_rv == -1)
    {
        perror("wait");
        exit(0);
    }

    return 0;
}
