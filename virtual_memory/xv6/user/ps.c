#include "kernel/types.h"
#include "kernel/uproc.h"
#include "user/user.h"

#define MAX_PROCS 64

char *states[] = {
[2] "SLEEPING",
[3] "RUNNABLE",
[4] "RUNNING ",
[5] "ZOMBIE  ",
};

void print_proc(struct uproc *proc)
{
    if (proc == 0)
    {
        printf("PID\tPPID\tSTATE\t\tMEM\tPRIO\tTICKS\tBLOCK\tFULL\tNAME\n");
        return;
    }
    printf("%d\t%d\t%s\t%d\t%d\t%d\t%d\t%d\t%s\n", proc->pid, proc->ppid, states[proc->state], proc->sz, proc->priority, proc->ticks, proc->block_times, proc->quantum_times, proc->name);
}

int main(int argc, char *argv[])
{
    if (argc != 1)
    {
        printf("usage: ps\n");
        exit(1);
    }

    struct uproc procs[MAX_PROCS];

    int num_procs = procinfo(procs, MAX_PROCS);
    if (num_procs == -1)
    {
        printf("procinfo error!");
        exit(1);
    }

    print_proc(0);
    for (int i=0; i<num_procs; ++i)
    {
        print_proc(&procs[i]);
    }

    return 0;
}
