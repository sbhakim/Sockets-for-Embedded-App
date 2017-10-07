/* What is UDP client socket */

#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFLEN 512
#define NPACK  10
#define PORT 9930

void diep (char *s)
{
    perror(s);
    exit(1);
}


int main (void)
{
    struct sockaddr_in si_me, si_other;
    int s, i, slen=sizeof(si_other);

    char buf[BUFLEN];

    if ((s = socket (AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
        diep ("socket");
}