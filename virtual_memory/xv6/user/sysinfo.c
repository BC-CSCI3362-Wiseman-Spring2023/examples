#include "kernel/types.h"
#include "kernel/sysinfo.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    if (argc != 1)
    {
        printf("usage: sysinfo\n");
        exit(1);
    }

    struct sysinfo info;

    if (sysinfo(&info) == -1)
    {
        printf("sysinfo error!");
        exit(1);
    }

    printf("Number of Hardware Threads: %d\n", info.num_harts);
    printf("Number of Processes: %d\n", info.num_procs);
    printf("Total Memory (bytes): %d\n", info.total_mem);
    printf("Available Memory (bytes): %d\n", info.avail_mem);
    printf("Process Memory (bytes): %d\n", info.proc_mem);

    return 0;
}
