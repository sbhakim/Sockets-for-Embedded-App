#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>


#define BUFLEN 512
#define NPACK   10
#define PORT  9930

void diep(char *s)
{
    perror(s);
    exit(1);
}

int main(void)
{
    struct sockaddr_in si_me, si_other;
    int n;
    int i;
    int slen = sizeof(si_other);
    char buf[BUFLEN];

    if ((n = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)   // "IPPROTO_UDP" the default value is 0    
        diep ("stocket initialization failed");

    
    memset ((char*) &si_me, 0, sizeof(si_me));               // initializing a block of memory, value with zero

    si_me.sin_family = AF_INET;                                
    si_me.sin_port   = htons(PORT);                          // We need famuly, port and address
    si_me.sin_addr.s_addr = hton1(INADDR_ANY);

    if (bind (n, &si_me, sizeof(si_me)) < 0)
        diep ("binding error");

    for (i = 0; i < NPACK; i++)
    {
        if (recvfrom(n, buf, BUFLEN, 0, &si_other, &slen) < 0)
            diep("recvfrom()");
        printf ("Received packet from %s:%d \n Data: %s \n\n",
            inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port), buf);
    }

    close(n);

    return 0;

}




