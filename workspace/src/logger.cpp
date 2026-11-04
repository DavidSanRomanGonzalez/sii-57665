#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int main(int argc, char **argv) {
    int fd;
    char buffer[1024];
    int n;
    // borrar FIFO por si existiera previamente
    unlink("/tmp/FIFO_LOGGER");

    /* crear el FIFO */
    if (mkfifo("/tmp/FIFO_LOGGER", 0777)<0) {
        perror("No puede crearse el FIFO");
        return(1);
    }
    /* Abrir el FIFO */
    if ((fd = open("/tmp/FIFO_LOGGER", O_RDONLY)) < 0) {
        perror("No puede abrirse el FIFO");
        return(1);
    }
    /* Leer de la FIFO */
    while ((n = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
	buffer[n] = '\0';
	printf("%s\n", buffer);
    }
    close(fd);
    unlink("/tmp/FIFO_LOGGER");
    return(0);
}
