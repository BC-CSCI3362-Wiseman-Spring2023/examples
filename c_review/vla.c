#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>

int main(int argc, char *argv[])
{
    if (argc != 2) 
    {
        printf("%s #elements\n", basename(argv[0]));
        exit(1);
    }

    int vals[atoi(argv[1])];

    vals[0] = 0;

    printf("%d\n", vals[0]);
    return 0;
}
