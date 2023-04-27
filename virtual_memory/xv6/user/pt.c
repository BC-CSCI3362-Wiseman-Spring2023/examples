#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    if (argc != 1)
    {
        printf("usage: pt\n");
        exit(1);
    }

    printf("before malloc()\n");
    print_pagetable();

    int *a = (int *)malloc(sizeof(int));

    printf("after malloc()\n");
    print_pagetable();

    free(a);

    return 0;
}
