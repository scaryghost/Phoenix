#include "Phoenix/Core/Common.h"

#include <cstdarg>
#include <exception>
#include <cstdlib>

namespace etsai {
namespace phoenix {

using std::va_list; 
using std::unordered_set;

float Common::displayHeight= 768;
float Common::displayWidth= 1024;

HINSTANCE Common::dllHandle;
Common::CreateSingleProjType Common::createSingleProj;
Common::CreateHumanPawnType Common::createHumanPawn;
Common::CreateHumanPawnType Common::createHitBox;
unordered_set<Object*> Common::objects;

void Common::init(int argc, char **argv) {
    displayWidth= atoi(argv[1]);
    displayHeight= atoi(argv[2]);

    dllHandle= LoadLibrary(TEXT("PhoenixAllegro5.dll"));
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

Object* Common::spawn(std::string className, ...) {
    Object* obj;
    va_list args;
    va_start(args, className);

    if (className == "HumanPawn") {
        double x= va_arg(args, double), y= va_arg(args, double);
        obj= createHumanPawn(x, y);
    } else if (className == "HitBox") {
        obj= createHitBox(va_arg(args, float), va_arg(args, float));
    } else if (className == "SingleProj") {
        obj= createSingleProj(va_arg(args, float), va_arg(args, float), va_arg(args, float));
    }
    va_end(args);
    objects.insert(obj);

    return obj;
}

void Common::drawObjects() {
    for(auto it= objects.begin(); it != objects.end(); it++) {
        (*it)->draw();
    }
}

}
}