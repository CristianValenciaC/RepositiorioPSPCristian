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
        printf("Cristian");//opcion 1
        //opcion 2: system("whoami");
    }
    else
    {
        printf("pid del proceso P2 = %d y pid del proceso P1 = %d\n", pid, getpid());
    }
}
