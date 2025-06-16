#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>



class SClient {
    public:
    SClient(std::string&& ip_to_connect, int&& port_to_connect); // конструктор.
    void connect_to_server(); // подключение к серверу.
    void disconnect_from_server(); // отключение от сервера.

    private:
    // variables
    std::string ip_to_connect; // IP-адрес.
    int port_to_connect; // Порт.
    int client_socket; // client socket.
    struct sockaddr_in server_addr; // структура сервера (IP, Port, семейство адресов)

    // functions
    void configure_sockaddr_in();
};

#endif