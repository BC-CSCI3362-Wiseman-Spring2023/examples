#include <stdio.h>

int my_func(int x)
{
    printf("In my_func(), x=%d\n", x);
    return x*x;
}

int my_func2(void)
{
    printf("In my_func2()\n");
    return 1;
}

int main()
{
    int r = my_func(10);
    printf("In main(), r=%d\n", r);

    int (*fp)(int);

    fp = my_func;

    int s = fp(20);
    printf("In main(), s=%d\n", s);

    printf("my_func=%p\n", my_func);
    printf("&my_func=%p\n", &my_func);
    printf("fp=%p\n", fp);
    printf("&fp=%p\n", &fp);

    // this would cause a compiler error:
    fp = my_func2;

    return 0;
}
