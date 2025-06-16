#include "client.h"


SClient::SClient(std::string&& ip_to_connect, int&& port_to_connect): ip_to_connect(ip_to_connect), port_to_connect(port_to_connect) {
    this->ip_to_connect = ip_to_connect; // инициализируем свойство класса значением из конструктора.
    this->port_to_connect = port_to_connect; // инициализируем свойство класса значением из конструктора.
    this->client_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // создаём объект сокета.
    this->configure_sockaddr_in();  // конфигурируем объект типа sockaddr_in
}

void SClient::connect_to_server() {
    if (connect(this->client_socket, (sockaddr*)&this->server_addr, sizeof(this->server_addr)) == 0) { // есои подключение к серверу успешно
        printf("Соединение успешно установлено к IP: %s и к порту %i.\n", this->ip_to_connect.c_str(), this->port_to_connect);
    }
    else { // если подключение не успешно
        printf("Ошибка при подключении к серверу.\n");
    }
}

void SClient::disconnect_from_server() {
    close(this->client_socket); // отключаемся от сервера. Освобождаем сокет.
    printf("Соединение разорвано.\n");
}

void SClient::configure_sockaddr_in() {
    this->server_addr.sin_addr.s_addr = inet_addr(this->ip_to_connect.c_str()); // iner_addr преобразует const char* ip-адрес в IP-адрес сетевого порядка
    this->server_addr.sin_family = AF_INET; // указываем свойство IPv4
    this->server_addr.sin_port = htons(this->port_to_connect); // htons() преобразует обычное числовое значение порта в сетевое значение порта.
}