#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void main()
{
	char mensaje[] = "00523821F";
	
	char ultimos4[5];
	
	strncpy(ultimos4,&mensaje[4],4);
	
	ultimos4[4] = '\0';
	
	printf("Inicio del programa\n");

	printf("Nombre del alumno:\n");
	printf("Cristian");
	printf("Ultimas cifras DNI: %s\n", ultimos4);
	system("ls -l --sort=size /home/alumno/Descargas \n");
	printf("\n");
	printf("El proceso se esta ejecutando en la terminal: \n");
	system("tty");
	printf("Me voy a dormir dos minutos... \n");
	sleep(120);
	printf("Informacion del proceso \n");
	system("ps -ef | grep 'ej11' \n");
	printf("\n");

	printf("Fin del programa\n");

}
