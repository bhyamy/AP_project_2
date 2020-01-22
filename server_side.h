//
// Created by bhyamy on 1/16/20.
//

#ifndef AP_PROJECT2_SERVER_SIDE_H
#define AP_PROJECT2_SERVER_SIDE_H

#include "ClientHandler.h"
namespace server_side {
    class Server {
    public:
        virtual void open(int port, ClientHandler* clientHandler) = 0;
        virtual void stop() = 0;
    };
};


#endif //AP_PROJECT2_SERVER_SIDE_H
