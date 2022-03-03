//
// Created by CottonCandyZ on 3/1/22.
//

#include <iostream>
#include <memory>
#include <utility>

struct connection {
    std::string ip;
    int port;

    connection(std::string ip_, int port_) : ip(std::move(ip_)), port(port_) {}
};

struct destination {
    std::string ip;
    int port;

    destination(std::string ip_, int port_) : ip(std::move(ip_)), port(port_) {}
};

connection connect(destination *pDest) {
    std::shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port));
    std::cout << "creating connection" << std::endl;
    return *pConn;
}

void disconnect(const connection &pConn) {
    std::cout << "connection close(" << pConn.ip << ":" << pConn.port << ")"
              << std::endl;
}

void end_connection(connection *pConn) {
    disconnect(*pConn);
}

void f(destination &d) {
    connection c = connect(&d);
    std::shared_ptr<connection> p(&c, [](connection *pConn) { disconnect(*pConn); });
}

int main() {
    destination d("127.0.0.1", 10);
    f(d);
    return 0;
}