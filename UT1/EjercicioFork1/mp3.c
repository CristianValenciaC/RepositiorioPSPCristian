#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

//Hecho por Cristian Valencia

void main()
{
    pid_t pid1, pid2;
    pid1 = fork();

    if (pid1 == 0)
    {
        sleep(10);
        printf("Despierto\n");
    }
    else
    {
        wait(NULL);
        pid2 = fork();
        if (pid2 == 0)
        {
            printf("pid del proceso del segundo hijo = %d\npid del proceso padre = %d\n", getpid(), getppid());
        }
        else
        {
            wait(NULL);
        }
        
        
    }
}
