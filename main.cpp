#include "Phoenix/Allegro5/A5HumanPawn.h"
#include "Phoenix/Core/Object.h"
#include "Phoenix/Core/HitBox.h"
#include "Phoenix/Core/Actor.h"
#include "Phoenix/Game/HumanPawn.h"

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"

#include <iostream>
#include <string>
#include <unordered_set>

#define PI 3.141592653589793238462643383279502

using std::cout;
using std::cerr;
using std::endl;
using std::get;
using std::string;
using std::unordered_set;
using namespace etsai::phoenix;

class A5HumanPawnImpl : public A5HumanPawn {
public:
    A5HumanPawnImpl(float xPos, float yPos) : A5HumanPawn(xPos, yPos) { }
    virtual void touch(Actor *actor) { al_draw_filled_circle(xPos, yPos, 10.0, al_map_rgb(255, 0, 0));}
};

int main(int argc, char **argv) {
    int width= atoi(argv[1]), height= atoi(argv[2]);
    float x= atof(argv[3]), y= atof(argv[4]);

    if(!al_init()) {
        cerr << "failed to initialize allegro!" << endl;
        return -1;
    }
    if(!al_install_keyboard()) {
        cerr << "failed to initialize the keyboard!" << endl;
        return -1;
    }
    if(!al_init_image_addon()) {
        cerr << "failed to initialize al_init_image_addon!" << endl;
        return -1;
   }
    al_init_primitives_addon();
    ALLEGRO_DISPLAY *display= al_create_display(width, height);
    ALLEGRO_EVENT_QUEUE *event_queue= al_create_event_queue();
    ALLEGRO_TIMER *timer= al_create_timer(1.0/30.0);
    ALLEGRO_EVENT ev;

    A5HumanPawnImpl *test= new A5HumanPawnImpl(100, 100);
    unordered_set<int> downKeys;

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_start_timer(timer);

    auto keyCheck= [&downKeys, &test]() -> void {
        if (downKeys.count(ALLEGRO_KEY_W)) {
            if (downKeys.count(ALLEGRO_KEY_A)) {
                test->setDirection(HumanPawn::Direction::UP_LEFT);
            } else if (downKeys.count(ALLEGRO_KEY_D)) {
                test->setDirection(HumanPawn::Direction::UP_RIGHT);
            } else {
                test->setDirection(HumanPawn::Direction::UP);
            }
        } else if (downKeys.count(ALLEGRO_KEY_S)) {
            if (downKeys.count(ALLEGRO_KEY_A)) {
                test->setDirection(HumanPawn::Direction::DOWN_LEFT);
            } else if (downKeys.count(ALLEGRO_KEY_D)) {
                test->setDirection(HumanPawn::Direction::DOWN_RIGHT);
            } else {
                test->setDirection(HumanPawn::Direction::DOWN);
            }
        } else if (downKeys.count(ALLEGRO_KEY_A)) {
            test->setDirection(HumanPawn::Direction::LEFT);
        } else if (downKeys.count(ALLEGRO_KEY_D)) {
            test->setDirection(HumanPawn::Direction::RIGHT);
        } else {
            test->setDirection(HumanPawn::Direction::NEUTRAL);
        }
    };

    do {
        al_wait_for_event(event_queue, &ev);

        switch(ev.type) {
            case ALLEGRO_EVENT_TIMER:
                Object::tickObjects(1.0/30.0);
                break;
            case ALLEGRO_EVENT_KEY_DOWN:
                downKeys.insert(ev.keyboard.keycode);
                keyCheck();
                break;
            case ALLEGRO_EVENT_KEY_UP:
                downKeys.erase(ev.keyboard.keycode);
                keyCheck();
                break;
        }
        al_clear_to_color(al_map_rgb(0,0,0));
        Object::drawObjects();
        Actor::checkCollisions(test);
        al_flip_display();
    } while(ev.type != ALLEGRO_EVENT_DISPLAY_CLOSE);

    al_destroy_display(display);
    return 0;
}