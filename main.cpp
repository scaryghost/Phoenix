#include "Phoenix/Core/Object.h"
#include "Phoenix/Core/HitBox.h"
#include "Phoenix/Core/Actor.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include <iostream>

#define PI 3.141592653589793238462643383279502

using std::cout;
using std::cerr;
using std::endl;
using std::get;
using namespace etsai::phoenix;

class AllegroHitBox : public HitBox {
public:
    AllegroHitBox(float xPos, float yPos) : HitBox(xPos, yPos) { }

    virtual void draw() {
        auto prev= boundaryOffsets.end() - 1;
        for(auto it= boundaryOffsets.begin(); it != boundaryOffsets.end(); it++) {
            al_draw_line(xPos + get<0>(*prev), yPos + get<1>(*prev), xPos + get<0>(*it), yPos + get<1>(*it), al_map_rgb(0, 255, 0), 2.0);
            prev= it;
        }
    }
};

class AllegroActor : public Actor {
public:
    AllegroActor(float xPos, float yPos) : Actor(xPos, yPos), count(0) {
        hitbox= new AllegroHitBox(xPos, yPos);
        hitbox->addBoundaryPoint(-50, -50);
        hitbox->addBoundaryPoint(-50, 50);
        hitbox->addBoundaryPoint(50, 50);
        hitbox->addBoundaryPoint(50, -50);
    }
    virtual ~AllegroActor() {
        delete hitbox;
    }

    virtual void draw() { }

    virtual void touch(Actor *actor) { al_draw_filled_circle(xPos, yPos, 10.0, al_map_rgb(255, 0, 0)); count++;}

    void rotate(float radians) const {
        hitbox->rotate(radians);
    }
private:
    int count;
};

int main(int argc, char **argv) {
    int width= atoi(argv[1]), height= atoi(argv[2]);
    float x= atof(argv[3]), y= atof(argv[4]);
    AllegroActor *test= new AllegroActor(100, 100), *test2= new AllegroActor(225, 100);

    test->addTimer(1.0/30.0, "rotate", [&test]() -> void {
        test->rotate(PI/180.0);
    });
    
    test2->addTimer(1.0/30.0, "rotate", [&test2]() -> void {
        test2->rotate(-PI/180.0);
    });

    if(!al_init()) {
        cerr << "failed to initialize allegro!" << endl;
        return -1;
    }
    if(!al_install_keyboard()) {
        cerr << "failed to initialize the keyboard!\n";
        return -1;
    }
    al_init_primitives_addon();
    ALLEGRO_DISPLAY *display= al_create_display(width, height);
    ALLEGRO_EVENT_QUEUE *event_queue= al_create_event_queue();
    ALLEGRO_TIMER *timer= al_create_timer(1.0/30.0);
    ALLEGRO_EVENT ev;

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_start_timer(timer);

    do {
        al_wait_for_event(event_queue, &ev);

        switch(ev.type) {
            case ALLEGRO_EVENT_TIMER:
                Object::tickObjects(1.0/30.0);
                break;
            case ALLEGRO_EVENT_KEY_CHAR:
                if (ev.keyboard.keycode == ALLEGRO_KEY_W) {
                    test->rotate(3.141592653589793238462643383279502/180.0);
                } else if (ev.keyboard.keycode == ALLEGRO_KEY_S) {
                    test->rotate(-3.141592653589793238462643383279502/180.0);
                }
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