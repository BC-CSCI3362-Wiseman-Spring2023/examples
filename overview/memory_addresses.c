#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>

int global_var;

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("usage: %s value sleep_time\n", basename(argv[0]));
        exit(1);
    }

    int local_var = 1138;

    global_var = atoi(argv[1]);
    printf("global_var(%p) = %i\n", &global_var, global_var);

    sleep(atoi(argv[2]));

    printf("global_var(%p) = %i\n", &global_var, global_var);

    printf("local_var is at %p, which is %lu\n", &local_var, (unsigned long)&local_var);

    return 0;
}
