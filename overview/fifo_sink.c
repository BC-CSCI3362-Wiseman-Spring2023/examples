#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO_NAME "tmp_fifo"

int main()
{
    // open the FIFO for reading
    int fifo = open(FIFO_NAME, O_RDONLY);
    if (fifo < 0)
    {
        perror("open");
        exit(1);
    }

    int bytes_read;
    char c;
    while ((bytes_read = read(fifo,&c,sizeof(char))) > 0)
    {
        printf("%c", c);
        fflush(stdout);
    }
    printf("\n");
    if(bytes_read < 0)
    {
        perror("read");
        exit(1);
    }

    // close the FIFO
    if (close(fifo) < 0)
    {
        perror("close");
        exit(1);
    }
    return 0;
}
