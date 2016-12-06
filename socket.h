#ifndef SOCKET_H
#define SOCKET_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
class ServerSocket
{
private:
    int sockfd, newsockfd, n;
    int d, t, pro;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
public:
    ServerSocket(int d, int t, int proto = 0);
    ~ServerSocket();
    void b(const unsigned port);
    void l(unsigned bl);
    void a();
    void r(char *msg);
};

#endif // SOCKET_H
