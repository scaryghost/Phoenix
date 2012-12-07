#include "Phoenix/Core/Object.h"

#include <utility>

namespace etsai {
namespace phoenix {

using std::get;
using std::make_pair;
using std::make_tuple;
using std::string;
using std::unordered_set;

unordered_set<Object*> Object::tickableObjects;
unordered_set<Object*> Object::objects;

void Object::tickObjects(double delta) {
    unordered_set<Object*> toDestroy;
    
    for(auto it= tickableObjects.begin(); it != tickableObjects.end(); it++) {
        (*it)->tick(delta);
        if ((*it)->destroy) {
            toDestroy.insert(*it);
        }
    }

    for(auto it= toDestroy.begin(); it != toDestroy.end(); it++) {
        delete (*it);
    }
}

void Object::drawObjects() {
    for(auto it= objects.begin(); it != objects.end(); it++) {
        (*it)->draw();
    }
}

Object::Object(float xPos, float yPos) : 
destroy(false),xPos(xPos),yPos(yPos) {
    enableTick();
    objects.insert(this);
}

Object::~Object() {
    disableTick();
    objects.erase(this);
}

void Object::addTimer(double period, std::string name, TimerFunc callBack) {
    auto info= make_tuple(period, 0.0, callBack);
    timers.insert(make_pair(name, info));
}

void Object::removeTimer(std::string name) {
    if (tickableObjects.count(this) != 0) {
        timers.erase(name);
    }
}

void Object::disableTick() {
    tickableObjects.erase(this);
}

void Object::enableTick() {
    if (tickableObjects.count(this) == 0) {
        tickableObjects.insert(this);
    }
}

void Object::tick(double delta) {
    for(auto it= timers.begin(); it != timers.end(); it++) {
        get<1>(it->second)+= delta;
        if (get<1>(it->second) >= get<0>(it->second)) {
            get<2>(it->second)();
            get<1>(it->second)= 0;
        }
    }
}

}   //namespace phoenix
}   //namespace etsai
