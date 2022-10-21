#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <string.h>

//Hecho por Cristian Valencia

void main(){

     /*Array para almacenar descriptores del fichero*/
     int fd[2];
     int fd2[2];
     char buffer[30];
     char letrasNIF[] = "TRWAGMYFPDXBNJZSQVHLCKE";
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
                
                write(fd[1], mensaje, 10);

                read(fd2[0], buffer, 10);

                printf("La letra del NIF es: %s \n", buffer);
     
     }
     
     else
     
     {
                close(fd[1]);// Cierra el descriptor de lectura

                read(fd[0], buffer, 10);

                int numeroDNI = atoi(buffer);

                char resultadoLetra[1];

                resultadoLetra[0] = letrasNIF[numeroDNI%23];

                close(fd2[0]);

                write(fd2[1], resultadoLetra, 10);

                wait(NULL);
     }
     
        
}
