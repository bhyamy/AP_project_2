//
// Created by bhyamy on 1/16/20.
//

#ifndef AP_PROJECT2_CLIENTHANDLER_H
#define AP_PROJECT2_CLIENTHANDLER_H


class ClientHandler {
public:
    virtual void handleClient(int socket) = 0;
    virtual ClientHandler* clone() = 0;
};


#endif //AP_PROJECT2_CLIENTHANDLER_H
