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


#define BUFLEN 256
#define NPACK 10

void error (char *msg){
    perror (msg);
    exit(1);
}


int main (int argc, char *argv[])
{
    int udpNewSoc;
    char buffer[BUFLEN];
    int portNo, nBytes;

    struct sockaddr_in serv_Addr, cli_Addr;         // delclaring the locations

    int slen = sizeof (cli_Addr);
    int i, bindVal;

    /* Creating new UDP socket */
    
    
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s \n", argv[0]);
        exit(0);
    }
    
    printf ("\n IPv4 UDP Server Started ...\n");

    udpNewSoc = socket (Af_INET, SOCK_DGRAM, 0);

    if (udpNewSoc < 0)
        error ("Error opening the socket");
    
    
    /* Allocation memory locations and figuring the portno*/

    bzero ((char*) &serv_Addr, sizeof (serv_Addr));
    portNo = atoi(argv[1]);
       

    /* Configuring the settings of Address struct */

    serv_Addr.sin_family = AF_INET;
    serv_Addr.sin_port  = htons (portNo);
    serv_Addr.sin_addr.s_addr = inet_addr ("127.0.0.1");

    

    /* Sockets Layer Call : bind() */

    bindVal = bind (udpNewSoc, (struct sockaddr *) &serv_Addr, sizeof(serv_Addr))

    if (bindVal < 0)
        error ("ERROR occured while binding");

    for (i = 0; i < NPACK; i++){
         nBytes = recvfrom (udpNewSoc, buffer, BUFLEN, 0, &cli_Addr, slen);
        
        if (nBytes < 0)
            error ("Error occued while receiving packets");

        printf ("Received packet from %s:%d \nData: %s\n\n", 
            inet_ntoa(cli_Addr.sin_addr), ntohs(cli_Addr.sin_port), buffer);
    }
        
       
    close(s);

    return 0;
    
}

