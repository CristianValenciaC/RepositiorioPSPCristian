#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main()
{
	printf("Nombre del alumno:\n");
	printf("Cristian\n");
	system("ls -l --sort=size /home/alumno/Descargas \n");
	printf("\n");
	printf("El proceso se esta ejecutando en la terminal: \n");
	system("tty \n");
	printf("Me voy a dormir un minuto... \n");
	sleep(60);
	printf("Informacion del proceso \n");
	system("ps -ef | grep 'ej11' \n");
	printf("\n");
	printf("Fin del programa.... \n");
}
