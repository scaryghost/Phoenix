#include "Phoenix/Core/Actor.h"

#include <stdexcept>

namespace etsai {
namespace phoenix {

using std::unordered_set;

unordered_set<Actor*> Actor::actors;

void Actor::checkCollisions(Actor* actor) {
    throw std::runtime_error("Not yet implemented!");
}

void Actor::drawActors() {
    for(auto it= actors.begin(); it != actors.end(); it++) {
        (*it)->draw();
    }
}

}
}