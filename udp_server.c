/* UDP supports unreliable transmission of data, mainly used for Apps */
/* In UDP, "SOCK_DGRAM" is used*/

/* The following program is a sever side program implemented for UDP */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#include <netdb.h>
#include <arpa/inet.h>


void error (char *msg){
    perror (msg);
    exit(1);
}


int main (int argc, char *argv[])
{
    int udpNewSoc;
    char buffer[256];
    int portno, nBytes;

    struct sockaddr_in serv_Addr, cli_Addr;         // delclaring the locations

    int n;

    /* Creating new UDP socket */
    udpNewSoc = socket (Af_INET, SOCK_DGRAM, 0);

    if (udpNewSoc < 0)
        error ("Error opening the socket");
    
    
    

    /* Configuring the settings of Address struct */

    serv_Addr.sin_family = AF_INET;
    serv_Addr.sin_port  = htons (portno);
    serv_Addr.sin_addr.s_addr = inet_addr ("127.0.0.1");

    bzero ((char*) serv_addr)




}

