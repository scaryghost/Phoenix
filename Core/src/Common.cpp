#include "Phoenix/Core/Common.h"

#include <cstdlib>

namespace etsai {
namespace phoenix {

void Common::init(int argc, char **argv) {
    displayWidth= atoi(argv[1]);
    displayHeight= atoi(argv[2]);
}

int Common::displayHeight= 768;
int Common::displayWidth= 1024;
}
}