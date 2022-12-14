#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/* gestión de señales en proceso padre       */
void manejador( int numsenal )
{
 printf("Hijo recibe señal número..%d\n", numsenal);
 
}

void manejadorPadre(int numsenal)
{
    printf("Padre recibe señal número ..%d\n", numsenal);
}

int main()
{
  int pid_hijo;  
  pid_hijo = fork(); //creamos hijo   
  
  switch(pid_hijo)
  {
     case -1:
          printf( "Error al crear el proceso hijo...\n");
          exit( -1 );
          break;        
     case 0:   //HIJO     	         
          signal(SIGUSR1, manejador); //Función manejadora de la señal
          pause();
          printf("Mando una señal al padre con ppid %d\n", getppid());
          kill(getppid(), SIGUSR2);
          break;    
     default: //PADRE envia 2 señales
          sleep(1);
          signal(SIGUSR2, manejadorPadre);
          printf("Mando una señal al hijo con ppid %d\n", pid_hijo);
          kill(pid_hijo, SIGUSR1);//ENVIA SEÑAL AL HIJO 
          pause();
          sleep(1);
          break;
  } 
  return 0;
}
