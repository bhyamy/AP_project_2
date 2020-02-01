#include "boot.h"

using namespace std;

int main(int argc, char** argv) {
    boot::Main main = boot::Main();
    main.main(argc, argv);
    return 0;
}
