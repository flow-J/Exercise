#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main()
{
    int serv_sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(1234);
    bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    listen(serv_sock, SOMAXCONN);

    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size = sizeof(clnt_addr);
    char buffer[100];
    while (true)
    {
        int clnt_sock = accept(serv_sock, (sockaddr*)&clnt_addr, &clnt_addr_size);
        int strlen = recv(clnt_sock, buffer,100,0);
        send(clnt_sock, buffer, strlen, 0);

        close(clnt_sock);
        close(serv_sock);

        return 0;
    }
}
