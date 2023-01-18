#include <stdio.h>
#include <string.h>

int main()
{
    char s[] = "This is the way.";
    int counts[26];

    for (int i=0; i<26; ++i)
    {
        counts[i] = 0;
    }

    for (int i=0; i<strlen(s); ++i)
    {
        if(s[i] >= 'A' && s[i] <= 'Z') 
        {
            counts[s[i]-'A']++;
        }
        else if(s[i] >= 'a' && s[i] <= 'z') 
        {
            counts[s[i]-'a']++;
        }
    }

    for (int i=0; i<26; ++i)
    {
        if(counts[i] != 0)
        {
            printf("%c: %i\n", i+'A', counts[i]);
        }
    }

    return 0;
}
