//
// Created by Serqey Cheremisin on 09/04/2017.
//

#ifndef HTTP_SERVER_CONFIGURATION_H
#define HTTP_SERVER_CONFIGURATION_H

class Configuration {
public:
    static const int PORT = 8000;
    static const int nWorkers = 1;
    static char *ROOT_DIR;
};

char *Configuration::ROOT_DIR = (char *) "./document_root";


#endif //HTTP_SERVER_CONFIGURATION_H
