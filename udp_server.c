/* -----------------------------------------------  */ 
#include <stdio.h>          /* For fprintf */
#include <stdlib.h>         
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>         /* For memcpy */
#include <netdb.h>

#define PORT 5678
#define BUFSIZE 2048

int main (int argc, char **argv){

	int sock;                           /* This is our socket file descriptor */
	int  bindVal;
	struct sockaddr_in6 my_addr;          /* our address */
	socklen_t addrlen = sizeof (my_addr);
	int recvlen;                        /* #bytes received */
	unsigned char buf[BUFSIZE];         /* receive buffer*/

	/* Creating a UDP socket */
	sock = socket (AF_INET6, SOCK_DGRAM, 0);
	if (sock < 0){
		perror ("Unable to create socket!! \n");
		return 0;
	}

	/* Bind the socket to any valid IP address and a specific port */

	memset ((char *) &my_addr, 0, sizeof(my_addr));
	my_addr.sin6_family = AF_INET6;
	//    my_addr.sin6_addr = htonl (in6addr_any);
	my_addr.sin6_addr = in6addr_any;
	my_addr.sin6_port = htons(PORT);

	bindVal = bind(sock, (struct sockaddr *) &my_addr, sizeof(my_addr));

	if (bindVal < 0){
		perror("bind failed");
		return 0;
	}
	/* now loop, receiving data and printing what we received */

	for (;;){
		printf ("Waiting on port %d\n", PORT);
		recvlen = recvfrom(sock, buf, BUFSIZE, 0, (struct sockaddr *) &my_addr, &addrlen);

		printf ("\nReceived %d bytes \n", recvlen);

		if (recvlen > 0){
			buf[recvlen] = 0;
			printf ("received message: \"%s\" \n", buf);
		}
		/* never exits */
	}
}

/* -----------------------------------------------  */