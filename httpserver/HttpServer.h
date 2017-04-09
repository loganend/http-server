#ifndef HTTP_SERVER_HTTPSERVER_H
#define HTTP_SERVER_HTTPSERVER_H

#include <event2/event.h>
#include <event2/listener.h>
#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <event2/thread.h>
#include "Client.h"
#include "WorkerQueue.h"

class HttpServer {
public:
    HttpServer();
    virtual ~HttpServer();
    void startServer(int port, int workers, char *rootDir);

private:
    static void connectionCallback(struct evconnlistener *lisnter, evutil_socket_t fd, struct sockaddr *address,
                                   int socklen, void *ctx);
    static void errotCallback(struct evconnlistener *listener, void *ctx);
    static void readCallback(struct bufferevent *bev, void *ctx);
    static void writeCallback(bufferevent *bev, void *ctx);
    static void eventCallback(struct bufferevent *bev, short events, void *ctx);

    static workerqueue_t workerqueue;
    static char *rootDir;
};


#endif //HTTP_SERVER_HTTPSERVER_H
