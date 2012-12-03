#include "Phoenix/Core/Object.h"

#include <utility>

namespace etsai {
namespace phoenix {

using std::make_pair;
using std::make_tuple;
using std::string;

Object::Object() {
}

Object::~Object() {
}

void Object::addTimer(double period, std::string name, TimerFunc callBack) {
    auto info= make_tuple(period, 0.0, callBack);
    timers.insert(make_pair(name, info));
}

void Object::removeTimer(std::string name) {
    timers.erase(name);
}

void Object::disableTick() {
    enableTick= false;
}

void Object::enableTick() {
    enableTick= true;
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
