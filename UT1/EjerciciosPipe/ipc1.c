#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <time.h>


void main(){

     /*Array para almacenar descriptores del fichero*/
     time_t hora;
     char *fecha ;
     time(&hora);
     fecha = ctime(&hora) ;

     int fd[2]; 
     char buffer[100];
     pid_t pid;
    
     // Creamos el pipe
     pipe(fd); 
     
     //Se crea un proceso hijo
     pid = fork();

     if (pid==0)
     
     {
                close(fd[1]); // Cierra el descriptor de lectura
                read(fd[0], buffer, 100);
                printf("Soy el hijo con el pid %d\nFecha/Hora: %s", getpid(), buffer);
                
     
     }
     
     else
     
     {
                close(fd[0]); // Cierra el descriptor de lectura
                write(fd[1], fecha, 100);
                wait(NULL);
     }
     
        
}