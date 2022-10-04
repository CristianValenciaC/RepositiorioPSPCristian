#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

//Hecho por Cristian Valencia

void main()
{
    pid_t pid, pid_hijo;
    pid = fork();

    if (pid == 0)
    {
        pid_hijo = fork();
        if (pid_hijo == 0)
        {
            printf("pid del proceso P3 = %d ; pid del proceso padre del P3 = %d\n", getpid(), getppid());
        }
        else
        {
            wait(NULL);
            printf("pid del proceso P2 = %d ; pid del proceso padre del P2 = %d\n", getpid(), getppid());
        }
    }
    else
    {
        wait(NULL);
        printf("pid del proceso hijo de P1 = %d y pid del proceso P1= %d\n", pid, getpid());
    }
}
