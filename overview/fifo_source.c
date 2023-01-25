#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO_NAME "tmp_fifo"

int main()
{
    // first make the FIFO
    if (mkfifo(FIFO_NAME, 0600) != 0)
    {
        perror("mkfifo");
        exit(1);
    }

    // open the FIFO for writing
    int fifo = open(FIFO_NAME, O_WRONLY);
    if (fifo < 0)
    {
        perror("open");
        exit(1);
    }

    for (char c='0'; c<='9'; ++c)
    {
        if (write(fifo, &c, sizeof(char)) != sizeof(char))
        {
            perror("write");
            exit(1);
        }
        sleep(1);
    }

    // close the FIFO
    if (close(fifo) < 0)
    {
        perror("close");
        exit(1);
    }

    // clean up the FIFO
    if (remove(FIFO_NAME) != 0)
    {
        perror("unlink");
        exit(1);
    }
    return 0;
}
