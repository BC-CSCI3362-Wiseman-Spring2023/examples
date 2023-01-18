#include <stdio.h>

int main()
{
    int x = 42;
    double a = -1.518;
    char c = 'A';
    char *s = "Hello there";

    printf("x=%i, a=%0.2f\n", x, a);
    printf("%c%c%c\n", c, c, c);
    printf("%s\n", s);
    return 0;
}
