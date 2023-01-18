#include <stdio.h>
#include <string.h>

int main()
{
    char s[] = "May the force be with you";
    char t[] = "The force will be with you, always";
    // this will give a compiler error:
    //s = t;
    printf("%s\n", s);

    char *u = "May the force be with you";
    char *v = "The force will be with you, always";
    u = v;
    printf("%s\n", u);

    char c = 'O';

    printf("&c=%p, c=%c\n", &c, c);
    printf("&s=%p, s=%p\n", &s, s);
    printf("&u=%p, u=%p\n", &u, u);

    return 0;
}
