//
// Created by iris on 21/01/2020.
//

#ifndef UNTITLED4_BOOT_H
#define UNTITLED4_BOOT_H

#include "MySerialServer.h"
#include "Solver.h"
#include "StringReverser.h"
#include "ClientHandler.h"

namespace boot {
    class Main {
    public:
        int main(int argc, char *argv[]) {
            server_side::Server* server = new MySerialServer();
            server->open(argv[1], )
        }
    };
}

#endif //UNTITLED4_BOOT_H
