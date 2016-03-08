#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main()
{
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(1234);

    char buf_send[100];
    char buf_recv[100];

    while (1)
    {
        int serv_sock = socket(AF_INET, SOCK_STREAM, 0);
        connect(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
        printf("Input a string: ");
        gets(buf_send);
        send(serv_sock, buf_send, strlen(buf_send), 0);
        recv(serv_sock, buf_recv, 100, 0);
        printf("Message form server: %s\n", buf_recv);

        memset(buf_send, 0, 100);
        memset(buf_recv, 0, 100);
        close(serv_sock);
    }

    return 0;
}
