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
            printf("proceso hijo pid = %d ; proceso padre pid = %d\n", getpid(), getppid());
        }
        else
        {
            wait(NULL);
            printf("proceso hijo pid = %d ; proceso padre pid = %d\n", getpid(), getppid());
        }
    }
    else
    {
        wait(NULL);
        printf("proceso hijo pid = %d ; proceso padre pid = %d\n", getpid(), getppid());
    }
}