#include "Phoenix/Core/Actor.h"

#include <stdexcept>

namespace etsai {
namespace phoenix {

std::unordered_set<Actor*> Actor::actors;

void Actor::checkCollisions(Actor* actor) {
    for(auto it= actors.begin(); it != actors.end(); it++) {
        if (actor != *it && actor->hitbox->collide((*it)->hitbox)) {
            actor->touch(*it);
            (*it)->touch(actor);
        }
    }
}

}
}