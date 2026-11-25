#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "DatosMemCompartida.h"
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char* argv[])
{
	DatosMemCompartida* datos;
	char *direccion;
	int fd;
	
	fd=open("/tmp/datosBot", O_RDWR);
	if (fd == -1)
	{
		perror("Error al abrir el archivo"); 
		return 1;
	}
	direccion=(char*)mmap(NULL, sizeof(DatosMemCompartida), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (direccion == MAP_FAILED)
	{
		perror("Error en la proyeccion mmap"); 
		return 1;
	}
	close(fd);
	datos=(DatosMemCompartida*)direccion;

	while(1)
	{
		usleep(250000);
		float centro_raqueta = (datos->raqueta1.y1 + datos->raqueta1.y2) / 2;
		float centro_raqueta_x=-6;
		if (datos->esfera.centro.y > centro_raqueta && datos->esfera.centro.x < centro_raqueta_x + 9)
			datos->accion = 1;
		else if (datos->esfera.centro.y < centro_raqueta && datos->esfera.centro.x < centro_raqueta_x + 9)
			datos->accion = -1;
		else
			datos->accion = 0;
	}
	return 0;
}
