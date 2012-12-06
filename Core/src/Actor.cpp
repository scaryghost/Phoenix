#include "Phoenix/Core/Actor.h"

namespace etsai {
namespace phoenix {

using std::unordered_set;

unordered_set<Actor*> Actor::actors;

void Actor::drawActors() {
    for(auto it= actors.begin(); it != actors.end(); it++) {
        (*it)->draw();
    }
}

Actor::Actor(int xPos, int yPos): Object(),
xPos(xPos), yPos(yPos) {
    actors.insert(this);
}

Actor::~Actor() {
    actors.erase(this);
}

}
}