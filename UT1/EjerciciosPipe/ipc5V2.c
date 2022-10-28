#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <string.h>

//Hecho por Cristian Valencia

char letraNif(int numero)
{
    char letrasNIF[] = "TRWAGMYFPDXBNJZSQVHLCKE";
    return letrasNIF[numero%23];
}

void main(){

     /*Array para almacenar descriptores del fichero*/
     int fd[2];
     int fd2[2];
     char buffer[30];
     char buffer2[2];
     pid_t pid;
    
     // Creamos el pipe
     pipe(fd);
     pipe(fd2);
     
     //Se crea un proceso hijo
     pid = fork();

     if (pid==0)
     
     {
                close(fd[0]);

                close(fd2[1]);

                int valorUsuario;

                char mensaje[8];

                printf("Introduce el número de tu dni: ");

                scanf("%d", &valorUsuario);

                sprintf(mensaje, "%d" ,valorUsuario);
                
                write(fd[1], mensaje, sizeof(mensaje));

                read(fd2[0], buffer2, sizeof(buffer2));

                printf("La letra del NIF es: %s \n", buffer2);
     
     }
     
     else
     
     {
                close(fd[1]);// Cierra el descriptor de lectura

                close(fd2[0]);
                
                read(fd[0], buffer, sizeof(buffer));

                int numeroDNI = atoi(buffer);

                char resultado = letraNif(numeroDNI);

                write(fd2[1], &resultado, sizeof(resultado));

                wait(NULL);
     }
     
        
}