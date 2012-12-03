#include "Phoenix/Core/Object.h"

#include <utility>

namespace etsai {
namespace phoenix {

using std::get;
using std::make_pair;
using std::make_tuple;
using std::string;
using std::unordered_set;

unordered_set<Object*> Object::tickedObjects;

Object::Object() {
    enableTick();
}

Object::~Object() {
    disableTick();
}

void Object::addTimer(double period, std::string name, TimerFunc callBack) {
    auto info= make_tuple(period, 0.0, callBack);
    timers.insert(make_pair(name, info));
}

void Object::removeTimer(std::string name) {
    if (tickedObjects.count(this) != 0) {
        timers.erase(name);
    }
}

void Object::disableTick() {
    tickedObjects.erase(this);
}

void Object::enableTick() {
    if (tickedObjects.count(this) == 0) {
        tickedObjects.insert(this);
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
