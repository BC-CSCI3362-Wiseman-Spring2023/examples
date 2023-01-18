#include <stdio.h>
#include <stdbool.h>

int main()
{
    int count = 10;

    while(--count)
    {
        printf("while loop %d", count);
        if (count % 2)
        {
            printf(" is odd\n");
        }
        else
        {
            printf(" is even\n");
        } 
    }

    for(; count <= 10; count += 2)
    {
        printf("for loop %d\n", count);
    }

    while(true)
    {
        if(count++ == 15) 
        {
            break;
        }
        printf("while(true) loop %d\n", count);
    }
    return 0;
}
