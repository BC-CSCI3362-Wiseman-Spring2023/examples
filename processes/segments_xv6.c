#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int globalvar=0;

int f()
{
    return 1;
}

int main(int argc, char **argv)
{
    void *init_sbrk = sbrk(0);
    int localvar=0;
    int *dynvar = (int *)malloc(sizeof(int));
    void *final_sbrk = sbrk(0);

    printf("&f         = %p\n", &f);
    printf("&main      = %p\n", &main);
    printf("&globalvar = %p\n", &globalvar);
    printf("&argc      = %p\n", &argc);
    printf("&dynvar    = %p\n", &dynvar);
    printf("&localvar  = %p\n", &localvar);

    printf("init_sbrk  = %p\n", init_sbrk);
    printf("dynvar     = %p\n", dynvar);
    printf("final_sbrk = %p\n", final_sbrk);
    return 0;
}
