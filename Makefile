all: build_server

build_server:
	g++ -std=c++11  -levent -levent_pthreads -lpthread -o server  main.cpp httpserver/Client.cpp httpserver/HttpServer.cpp httpserver/Workerqueue.cpp httpserver/MimeType.cpp httpserver/HttpResponse.cpp httpserver/HttpRequest.cpp httpserver/HttpRequestParser.cpp httpserver/HttpRequestHandler.cpp

clean:
	rm -rf *.o server
