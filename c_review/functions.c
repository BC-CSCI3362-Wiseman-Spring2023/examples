#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

int *initialize_counts()
{
    int *counts = (int *)malloc(sizeof(int)*ALPHABET_SIZE);
    if (counts == NULL)
    {
        printf("Memory error!\n");
        exit(1);
    }
    for (int i=0; i<26; ++i)
    {
        counts[i] = 0;
    }
    return counts;
}

int *count_letters(char *str)
{
    int *counts = initialize_counts();
    for (int i=0; i<strlen(str); ++i)
    {
        if(str[i] >= 'A' && str[i] <= 'Z') 
        {
            counts[str[i]-'A']++;
        }
        else if(str[i] >= 'a' && str[i] <= 'z') 
        {
            counts[str[i]-'a']++;
        }
    }
    return counts;
}

void print_counts(int *counts)
{
    for (int i=0; i<26; ++i)
    {
        if(counts[i] != 0)
        {
            printf("%c: %i\n", i+'A', counts[i]);
        }
    }
}

int main()
{
    char s[] = "This is the way.";

    int *counts = count_letters(s);
    print_counts(counts);

    return 0;
}
