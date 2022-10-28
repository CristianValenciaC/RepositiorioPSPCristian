#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <string.h>
#include <time.h>

void calculo(int num1, int num2)
{
    printf("%d + %d = %d\n",num1, num2, num1+num2);
    printf("%d - %d = %d\n", num1, num2, num1-num2);
    printf("%d * %d = %d\n", num1, num2, num1*num2);
    printf("%d / %d = %d\n", num1, num2, num1/num2);
}

void main()
{
    pid_t pid;
    int fd[2];
    int fd2[2];
    char bufferPipe1[30];
    char bufferPipe2[30];

    pipe(fd);

    pid = fork();

    if (pid == 0)
    {
        close(fd[0]);
        srand(time(NULL));
        int numero1 = rand() % 51;
        srand(time(NULL)*2);
        int numero2 = rand() % 51 +1;
        char mensaje1[10];
        char mensaje2[10];
        sprintf(mensaje1, "%d", numero1);
        sprintf(mensaje2, "%d", numero2);
        write(fd[1], mensaje1, 10);
        write(fd[1], mensaje2, 10);
    }
    else
    {
        close(fd[1]);
        read(fd[0], bufferPipe1, 10);
        int num1 = atoi(bufferPipe1);
        wait(NULL);
        read(fd[0], bufferPipe2, 10);
        int num2 = atoi(bufferPipe2);
        calculo(num1, num2);
    }
    
}