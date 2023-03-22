#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage()
{
    printf("usage: function_ptr3 x op y\n");
    printf("where op is +,-,*,/\n");
    exit(1);
}

double add(double x, double y)
{
    return x+y;
}

double subtract(double x, double y)
{
    return x-y;
}

double multiply(double x, double y)
{
    return x*y;
}

double divide(double x, double y)
{
    return x/y;
}

double badarg(double x, double y)
{
    usage();
    return 0;
}

// would really use a hash for this to make it simpler...
/* From ASCII:
 *   '*'==42
 *   '+'==43
 *   '-'==45
 *   '/'==47
 * So, use these indices:
 *   multiply 0 (42-42)
 *   add 1 (43-42)
 *   subtract 3 (45-42)
 *   divide 5 (47-42)
 * And use a placeholder function to print an error for 
 * indices 2,4
 */
double (*ops[])(double, double) = {
    multiply,
    add,
    badarg,
    subtract,
    badarg,
    divide
};

int main(int argc, char *argv[])
{
    if (argc != 4 || (strlen(argv[2]) != 1))
    {
        usage();
    }

    int op = argv[2][0] - '*';
    if (op < 0 || op > 5)
    {
        usage();
    }
    double x = atof(argv[1]);
    double y = atof(argv[3]);

    double z = ops[op](x,y);
    printf("%g\n",z);
    return 0;
}
