#include "Phoenix/Core/Actor.h"

#include <stdexcept>

namespace etsai {
namespace phoenix {

std::unordered_set<Actor*> Actor::actors;

Actor::Actor(float xPos, float yPos) : Object(xPos, yPos) {
    //actors.insert(this);
}

Actor::~Actor() {
    actors.erase(this);
    delete hitbox;
}

void Actor::rotate(float radians) {
    Object::rotate(radians);
    hitbox->rotate(radians);
}

void Actor::translate(float xOffset, float yOffset) {
    Object::translate(xOffset, yOffset);
    hitbox->translate(xOffset, yOffset);
}

void Actor::checkCollisions() {
    for(auto it= actors.begin(); it != actors.end(); it++) {
        if (this != *it && this->hitbox->collide((*it)->hitbox)) {
            this->touch(*it);
            (*it)->touch(this);
        }
    }
}

}
}