// Server side C/ C++ program to demonstrate Socket Programming

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

#include <netinet/in.h>

#define PORT 8080

int main (int argc, int *argv[])
{
    int server_fd, new_socket, valread;

    struct sockaddr_in address;              // defining the socket
    int opt = 1;
    int addrlen = sizeof(address);

    char buffer[1024] ={0};

    char *hello = "Hello from server";

    // Creating socket file descriptor

    if ((server_fd = socket(AF)INET, SOCK_STREAM, 0) == 0)
    {
        perror ("socket failed");
        exit (EXIT_FAILURE);
    }

    // Forefully attaching socket to the port 8080

    if (setsocopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit (EXIT_FAILURE);
    }

    address.sin_family      = AF_INET;              // family
    address.sin_addr.s_addr = INADDR_ANY            // Address
    address.sin_port        = htons (PORT)          // port

    // Forefully attaching sokcet to the port 8080
    // bind will generate either 0 or 1

    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0)
    {   
        perror ("bind failed");
        exit (EXIT_FAILURE);
    }

    if  (listen(server_fd, 3) < 0)
    {
        perror ("bind failed");
        exit (EXIT_FAILURE;
    }

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*) &addrlen)) < 0)
    {
        perror("accept");
        exit (EXIT_FAILURE);
    }

    valread = read (new_socket, buffer, 1024);
    printf ("%s \n", buffer);
    send(new_socket, hello, strlen(hello), 0);
    printf ("Hello message sent \n");

    return 0;
}