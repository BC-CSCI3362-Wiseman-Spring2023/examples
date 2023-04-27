#include "kernel/types.h"
#include "user/user.h"

void do_work(int ticks)
{
    if(ticks > 0)
    {
        int start_ticks = uptime();
        while(uptime() - start_ticks < ticks)
        {
        }
    }
}

void do_sleep(int ticks)
{
    if(ticks > 0)
    {
        sleep(ticks);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("usage: worker work_ticks sleep_ticks\n");
        exit(1);
    }

    int work_ticks = atoi(argv[1]);
    int sleep_ticks = atoi(argv[2]);

    for(;;)
    {
        do_work(work_ticks);
        do_sleep(sleep_ticks);
    }

    return 0;
}
