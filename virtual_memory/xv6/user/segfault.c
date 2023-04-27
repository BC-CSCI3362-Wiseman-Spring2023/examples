#include "kernel/types.h"
#include "user/user.h"

int
f(int x)
{
    printf("In f(%d)\n", x);
    int *p = (int *)-1;
    int y = *p;
    return y;
}

int 
g(int a, int b)
{
    printf("In g(%d,%d)\n", a, b);
    return f(a+b);
}

int
main(int argc, char *argv[])
{
    printf("In main()\n");
    printf("%d\n", g(1, 2));

    return 0;
}
