#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    int *p = (int *)-1;
    printf("%p\n", *p);

    return 0;
}
