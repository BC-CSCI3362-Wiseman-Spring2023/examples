#define _XOPEN_SOURCE 500 // needed for sbrk() on cscigpuXX

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern int etext;
extern int end;

int globalvar=0;

int main(int argc, char **argv)
{
    void *init_sbrk = sbrk(0);
    int localvar=0;
    int *dynvar = (int *)malloc(sizeof(int));

    printf("&main      = %p\n", &main);
    printf("&etext     = %p\n", &etext);
    printf("&globalvar = %p\n", &globalvar);
    printf("&end       = %p\n", &end);
    printf("init_sbrk  = %p\n", init_sbrk);
    printf("dynvar     = %p\n", dynvar);
    printf("&argc      = %p\n", &argc);
    printf("&localvar  = %p\n", &localvar);
    printf("&dynvar    = %p\n", &dynvar);
    return 0;
}
