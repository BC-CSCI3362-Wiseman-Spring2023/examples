#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    printf("BEEP\n");

    if(close(STDOUT_FILENO) != 0)
    {
        perror("close");
        exit(1);
    }

    int fd = open("stuff.txt", O_WRONLY|O_CREAT|O_TRUNC, 0600);
    if (fd < 0)
    {
        perror("open");
        exit(1);
    }

    printf("got fd=%d!?\n", fd);
    printf("BOOP\n");

    if(close(fd) != 0)
    {
        perror("close");
        exit(1);
    }

    return 0;
}
