#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("usage: sleep num_seconds\n");
        exit(-1);
    }

    int num_seconds = atoi(argv[1]);
    if (num_seconds < 1)
    {
        printf("must sleep for at least one second!\n");
        printf("usage: sleep num_seconds\n");
        exit(-1);
    }

    int num_ticks = num_seconds*10;

    if (sleep(num_ticks) != 0)
    {
        printf("sleep error!\n");
        exit(-1);
    }

    return 0;
}
