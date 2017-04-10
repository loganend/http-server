#include <getopt.h>
#include "httpserver/HttpServer.h"
#include <iostream>

using namespace http::server;

int main(int argc, char **argv) {

    int port = 0;
    int workers = 0;
    char *rootDir = nullptr;
    int opt = 0;

    while ((opt = getopt(argc, argv, "p:w:r")) != -1) {
        switch (opt) {
            case 'p':
                port = std::atoi(optarg);
                if (port < 1 || port > 65535) {
                    std::cout << "Wrong port: " << port << std::endl;
                    return 0;
                }
                break;
            case 'w':
                workers = std::atoi(optarg);
                if (workers < 1) {
                    std::cout << "Wrong workers: " << workers << std::endl;
                    return 0;
                }
                break;
            case 'r':
                rootDir = optarg;
                if (rootDir[strlen(rootDir) - 1] == '/') {
                    rootDir[strlen(rootDir) - 1] = '\0';
                }
        }
    }

    HttpServer *httpServer = new HttpServer();
    httpServer->startServer(port, workers, rootDir);
    delete httpServer;

    return 0;
}

//-I /usr/local/include  -arch x86_64 -Xarch_x86_64