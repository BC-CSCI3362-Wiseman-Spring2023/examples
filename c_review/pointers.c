#include <stdio.h>

int main()
{
    int x = 42;

    // p is a pointer to an int, initialized to point to x
    int *p = &x;

    printf("x=%i\n", x);
    printf("*p=%i\n\n", *p);

    printf("Set x to 21.\n");
    x = 21;
    printf("x=%i\n", x);
    printf("*p=%i\n\n", *p);

    printf("Set *p to 10.\n");
    *p = 10;
    printf("x=%i\n", x);
    printf("*p=%i\n\n", *p);

    printf("&x=%p\n", &x);
    printf("p=%p\n", p);
    printf("&p=%p\n\n", &p);

    int *y = NULL;
    printf("Set y to NULL.\n");
    printf("y=%p\n\n",y);

    printf("This will now segfault, doing *y.\n");
    printf("*y=%i\n\n", *y);

    return 0;
}
