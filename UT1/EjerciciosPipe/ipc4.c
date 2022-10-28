#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <string.h>
#include <time.h>

long factorial(int n)
{
    int c;
    long result = 1;

    for (c = 1; c <= n; c++){
        result = result * c;
    }

    return result;
}

void main()
{
    pid_t pid;
    int fd[2];
    int fd2[2];
    char bufferPipe1[30];
    char bufferPipe2[30];

    pipe(fd);
    pipe(fd2);

    pid = fork();

    if (pid == 0)
    {
        close(fd[1]);
        close(fd2[0]);
        char mensaje2[10];
        read(fd[0], bufferPipe1, 10);
        int numero = atoi(bufferPipe1);
        long resultado = factorial(numero);
        sprintf(mensaje2, "%ld" , resultado);
        write(fd2[1], mensaje2, 10);
    }
    else
    {
        close(fd[0]);
        close(fd2[1]);
        srand(time(NULL));
        int numeroFactorial = rand() % 11;
        char mensaje[10];
        printf("El proceso padre genera el numero %d en el pipe1\n", numeroFactorial);
        sprintf(mensaje, "%d" ,numeroFactorial);
        write(fd[1], mensaje, 10);
        wait(NULL);
        read(fd2[0], bufferPipe2, 10);
        printf("El factorial calculado por el proceso hijo: %d!= %s\n", numeroFactorial, bufferPipe2);
    }
    
}