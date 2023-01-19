#include <stdio.h>
#include <stdlib.h>

#include "common.h"

void error_out(char *msg)
{
    printf("Error! %s\n", msg);
    exit(1);
}
