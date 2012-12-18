#include "Phoenix/Core/Common.h"

#include <exception>
#include <cstdlib>

namespace etsai {
namespace phoenix {

int Common::displayHeight= 768;
int Common::displayWidth= 1024;

HINSTANCE Common::dllHandle;
Common::CreateSingleProjType Common::createSingleProj;
Common::CreateHumanPawnType Common::createHumanPawn;
Common::CreateHumanPawnType Common::createHitBox;

void Common::init(int argc, char **argv) {
    displayWidth= atoi(argv[1]);
    displayHeight= atoi(argv[2]);

    dllHandle= LoadLibrary(TEXT("Allegro5.dll"));
    if (!dllHandle) {
        throw std::exception("Error loading dll");
    }
    createSingleProj= reinterpret_cast<CreateSingleProjType>(GetProcAddress(dllHandle, "createSingleProj"));
    if (!createSingleProj) {
        FreeLibrary(dllHandle);
        throw std::exception("Unable to load createSingleProj");
    }
    createHumanPawn= reinterpret_cast<CreateHumanPawnType>(GetProcAddress(dllHandle, "createHumanPawn"));
    if (!createHumanPawn) {
        FreeLibrary(dllHandle);
        throw std::exception("Unable to load createHumanPawn");
    }
    createHitBox= reinterpret_cast<CreateHumanPawnType>(GetProcAddress(dllHandle, "createHitBox"));
    if (!createHitBox) {
        FreeLibrary(dllHandle);
        throw std::exception("Unable to load createHitBox");
    }
}

}
}