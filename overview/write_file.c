#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("usage: %s filename\n", basename(argv[0]));
        exit(1);
    }

    int fd;
    fd = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, 0600);
    if (fd == -1)
    {
        perror("open failed for output.txt");
        exit(1);
    }

    char msg[] = "These are not the droids you're looking for...\n";
    int size = write(fd, msg, strlen(msg));
    if (size < 0)
    {
        perror("write");
        exit(1);
    }
    printf("Wrote %i bytes: %s", size, msg);

    if (close(fd) < 0)
    {
        perror("close");
        exit(1);
    }

    return 0;
}
