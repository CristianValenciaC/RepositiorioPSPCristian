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
            printf("proceso hijo pid = %d\n proceso padre pid = %d\n", getpid(), getppid());
        }
        wait(NULL);
        
    }
}
