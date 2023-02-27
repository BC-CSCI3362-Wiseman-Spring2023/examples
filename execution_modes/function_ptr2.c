#include <stdio.h>

int my_func(int x)
{
    printf("In my_func(), x=%d\n", x);
    return x*x;
}

int my_func2(int y)
{
    printf("In my_func2(), y=%d\n", y);
    return y+1;
}

int main()
{
    int (*fp)(int);

    fp = my_func;
    int s = fp(20);
    printf("In main(), s=%d\n", s);

    fp = my_func2;
    int t = fp(20);
    printf("In main(), t=%d\n", t);

    return 0;
}
