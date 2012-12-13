#include "Phoenix/Core/Common.h"
#include "Phoenix/Game/Dosh.h"
#include "Phoenix/Game/HumanPawn.h"

namespace etsai {
namespace phoenix {

Dosh::Dosh(float xPos, float yPos, unsigned int value) : SingleProj(xPos, yPos, PI/2), value(value) {
}

void Dosh::touch(Actor* actor) {
    HumanPawn* humanP= dynamic_cast<HumanPawn*>(actor);
    if (humanP != NULL) {
        humanP->addCash(value);
        destroy= true;
    }
}

}
}