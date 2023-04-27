#include "kernel/types.h"
#include "user/user.h"

char *simple_itoa(int x)
{
    int length = 1;
    int tmp = x;
    while (tmp)
    {
        length += 1;
        tmp /= 10;
    }

    if (x == 0)
    {
        length += 1;
    }

    char *s = (char *)malloc(length*sizeof(char));
    if (s == 0)
    {
        printf("malloc error");
        exit(1);
    }

    tmp = x;
    int index = length-1;
    s[index] = '\0';
    --index;
    s[index] = (tmp % 10) + '0';
    --index;
    while(tmp)
    {
        tmp /= 10;
        s[index] = (tmp % 10) + '0';
        --index;
    }

    return s;
}

void start_task(int work_ticks, int sleep_ticks)
{
    int forkret = fork();
    if (forkret == -1)
    {
        printf("fork error");
        exit(1);
    }
    if (forkret > 0)
    {
        return;
    }

    char *args[4];
    args[0] = "worker";
    args[1] = simple_itoa(work_ticks);
    args[2] = simple_itoa(sleep_ticks);
    args[3] = 0;

    exec(args[0], args);
    printf("exec error");
    exit(1);
}

int main(int argc, char *argv[])
{
    if (argc != 1)
    {
        printf("usage: mfqtest\n");
        exit(1);
    }

    start_task(1, 0);
    start_task(1, 0);
    start_task(1, 0);
    start_task(1, 0);

    start_task(5, 20);

    start_task(3, 20);

    start_task(1, 20);
    return 0;
}
