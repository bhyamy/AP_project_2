//
// Created by iris on 21/01/2020.
//

#ifndef UNTITLED4_BOOT_H
#define UNTITLED4_BOOT_H

#include "MyParallelServer.h"
#include "MyRealClientHandler.h"

namespace boot {
    class Main;
}
class boot::Main {
public:
   Main() {};
   ~Main() {};
   int main(int argc, char** argv) {
       server_side::Server* server = new MyParallelServer();
       ClientHandler* clientHandler = new MyRealClientHandler();
       try {
           server->open(argc < 2? 5600 : stoi(argv[1]), clientHandler);
       } catch (const char* e) {
           cout << e << endl;
       }
       return 0;
   }
};



#endif //UNTITLED4_BOOT_H
