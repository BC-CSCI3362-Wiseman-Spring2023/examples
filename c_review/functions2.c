#include <stdio.h>
#include <stdlib.h>

void f(int i)
{
    ++i;
}

void g(int *i)
{
    ++(*i);
}

int main()
{
    int x = 421;

    int *p = (int *)malloc(sizeof(int));
    if (p == NULL)
    {
        printf("Out of memory!\n");
        exit(1);
    }
    *p = 2187;

    printf("Before f, x=%i\n", x);
    f(x);
    printf("After f, x=%i\n", x);
    g(&x);
    printf("After g, x=%i\n", x);

    printf("Before f, *p=%i\n", *p);
    f(*p);
    printf("After f, *p=%i\n", *p);
    g(p);
    printf("After g, *p=%i\n", *p);

    free(p);

    return 0;
}
