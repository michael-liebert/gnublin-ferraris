#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include <time.h> 
 
const char *filename="/sys/class/gpio/gpio11/value";
 
 
void main(int argc, char **argv)
{
 
	struct pollfd *poll_fd;
	int fd;
	int pv;
	int bytes_read;
	char buf[2];
 
	fd = open(filename, O_RDWR);
	if(fd < 0) {
		printf("Error opening file %s", filename);
		exit(0);
	}
 
	/* initialize the pollfd structure */
	poll_fd = malloc(sizeof(*poll_fd));
	poll_fd->fd = fd;
	poll_fd->events = POLLPRI;
	poll_fd->revents = 0;
 
 	int counter = 0;
	time_t rawtime;

	while (1) {
	/* call read systemcall on file 
         * this has to be called before poll
         */
	bytes_read = read(fd, buf, 1);
 
 
	/* start poll method with no (-1) timeout 
         */	
	pv = poll(poll_fd, 1, -1);
	if(!pv) {
		puts("Poll timeout!\n");
		exit(0);
 
	} else if(pv == -1) {
		puts("Error while polling!\n");
		exit(0);
	} /* poll */
 
	time(&rawtime); 
	printf("%d %s", ++counter, asctime(localtime(&rawtime)));
	}
	close(fd);
 
}

