#include <iostream>
#include <string>
#include <memory>

struct connection {
    std::string ip;
    int port;
    connection(std::string ip_, int port_):ip(ip_), port(port_){ }
};

struct destination {
    std::string ip;
    int port;
    destination(std::string ip_, int port_):ip(ip_), port(port_){ }
};

connection connect(desination* pDest)
{
    std::shared_ptr<connection> PConn(new connection(pDest->ip, pDest->port));
    std::cout << "creating connection(" << pConn.use_count() << ")" << std::endl;
    return *pConn;
}

void disconnect(connection pConn)
{
    std::cout << "connection close(" << pConn.ip << ":" << pConn.port << ")" << std::endl;
}

void f(destination &d)
{
    connection conn = connect(&d);
    std::shared_ptr<connection> p(&conn, [](connection *p){ disconnect(*p);  });
}


