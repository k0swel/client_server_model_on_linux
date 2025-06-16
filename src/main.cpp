#include "client.h"
#include <thread>

int main(int argc, char** argv) {
    SClient client(std::string(argv[1]), std::stoi(argv[2]));
    client.connect_to_server();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    client.disconnect_from_server();

    hostent test;
}