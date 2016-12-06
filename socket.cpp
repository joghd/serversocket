#include "socket.h"
ServerSocket::ServerSocket(int domain, int type, int protocol):
    d(domain),
    t(type),
    pro(protocol)
{
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    bzero(buffer,256);
    clilen = sizeof(cli_addr);
}

void ServerSocket::b(const unsigned port){
    serv_addr.sin_family = d;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0)
        throw("[critical] error binding.");
}

void ServerSocket::l(unsigned bl){
    if( listen(sockfd,bl) < 0)
        throw("[critical] error listening.");
}

void ServerSocket::a(){
    newsockfd = accept(sockfd,
                (struct sockaddr *) &cli_addr,
                &clilen);
    if (newsockfd < 0)
        throw("[critical] error accepting connection.");
}

void ServerSocket::r(char *msg){
    n = read(newsockfd,buffer,255);
    if (n < 0) throw("[critical] error reading from socket");
    strcpy(msg, buffer);
}

ServerSocket::~ServerSocket(){
    close(newsockfd);
    close(sockfd);
}
