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

    global_var = atoi(argv[1]);
    printf("global_var(%p) = %i\n", &global_var, global_var);

    sleep(atoi(argv[2]));

    printf("global_var(%p) = %i\n", &global_var, global_var);

    return 0;
}
