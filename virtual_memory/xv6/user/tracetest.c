#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    trace(1);

    sleep(20);

    trace(0);

    sleep(20);

    return 0;
}
