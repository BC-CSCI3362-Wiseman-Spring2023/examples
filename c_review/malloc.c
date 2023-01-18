#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p = (int *)malloc(sizeof(int));
    if (p == NULL)
    {
        printf("Out of memory!\n");
        exit(1);
    }

    *p = 2187;

    printf("%i\n", *p);

    free(p);

    return 0;
}
