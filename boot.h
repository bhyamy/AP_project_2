//
// Created by iris on 21/01/2020.
//

#ifndef UNTITLED4_BOOT_H
#define UNTITLED4_BOOT_H

#include "MySerialServer.h"
#include "MyTestClientHandler.h"

namespace boot {
    class Main;
}
//todo fix main
class boot::Main {
public:
   Main() {};
   ~Main() {};
   int main(int argc, char** argv) {
       server_side::Server* server = new MySerialServer();
       ClientHandler* clientHandler = new MyTestClientHandler();
       try {
           server->open(stoi(argv[1]), clientHandler);
       } catch (const char* e) {
           cout << e << endl;
       }
       return 0;
   }
};



#endif //UNTITLED4_BOOT_H
