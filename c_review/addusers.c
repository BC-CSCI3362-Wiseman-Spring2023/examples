#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>

#include "userlist.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("usage: %s name [name...]\n", basename(argv[0]));
        exit(1);
    }

    usernode *userlist = make_user_list();
    for (int i=1; i<argc; ++i)
    {
        add_user(userlist, i-1, argv[i]);
    }

    print_users(userlist);

    destroy_user_list(userlist);

    return 0;
}
