#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include <arpa/inet.h>

void error (char *msg)
{
    perror(msg);
    exit(1);
}

/* sockfd is the socket function descriptor */
/* sockfd is the socket function descriptor */

int main(int argc, char *argv[])
{
    int sockfd, newsocfd, protno;
    soclen_t clilen;            /* client length*/

    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;


    if (argc < 2)
    {
        fprintf (stderr, "Usage: %s \n", argv[0]);
        exit(0);
    }

}