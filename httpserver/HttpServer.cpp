#include <stdexcept>
#include <cstring>
#include "HttpServer.h"
#include "Configuration.h"



HttpServer::HttpServer() {
    evthread_use_pthreads();
}

HttpServer::~HttpServer() {}

void HttpServer::startServer(int port, int nWorkers, char *rootDir) {
    struct sockaddr_in listenAddr;
    struct event_base *base;
    struct evconnlistener *listener;

    if(rootDir == nullptr){
        HttpServer::rootDir = Configuration::ROOT_DIR;
    }else{
        HttpServer::rootDir = rootDir;
    }
    if(port == 0){
        port = Configuration::PORT;
    }
    if(nWorkers == 0){
        nWorkers = Configuration::nWorkers;
    }

    base = event_base_new();
    if(evthread_make_base_notifiable(base) < 0){
        event_base_free(base);
        throw std::runtime_error("Couldn't make base notifiable!");
    }

    memset(&listenAddr, 0, sizeof(listenAddr));
    listenAddr.sin_family = AF_INET;
    listenAddr.sin_addr.s_addr = htonl(0);
    listenAddr.sin_port = htons(port);

    WorkerQueue::workerqueueInit((workerqueue_t *) &workerqueue, nWorkers);
    listener = evconnlistener_new_bind(base, connectionCallback, (void *) &workerqueue,
                                       LEV_OPT_CLOSE_ON_FREE | LEV_OPT_REUSEABLE | LEV_OPT_THREADSAFE, SOMAXCONN,
                                       (struct sockaddr *) &listenAddr, sizeof(listenAddr));



}


void HttpServer::connectionCallback(evconnlistener *listener, int fd, sockaddr *address, int socklen, void *arg) {

}