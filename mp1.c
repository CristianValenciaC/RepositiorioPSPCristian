#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

//Hecho por Cristian Valencia

void main()
{
    pid_t pid;
    pid = fork();

    if (pid == 0)
    {
        system("whoami\n");
    }
    else
    {
        printf("proceso hijo pid = %d ; proceso padre pid = %d\n", getpid(), getppid());
    }
}
