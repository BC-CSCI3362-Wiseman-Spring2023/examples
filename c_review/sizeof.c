#include <stdio.h>
#include <stdlib.h>

void func(int a[])
{
    printf("func: sizeof(a)=%lu\n", sizeof(a));
    printf("func: Length of a=%lu\n", sizeof(a)/sizeof(a[0]));
}

int main()
{
    int a[] = {0, 1, 4, 9, 16, 25};

    printf("main: sizeof(a)=%lu\n", sizeof(a));
    printf("main: Length of a=%lu\n", sizeof(a)/sizeof(a[0]));

    func(a);

    return 0;
}
