#include "Phoenix/Core/Object.h"
#include "Phoenix/Core/Actor.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include <iostream>

using std::cerr;
using std::endl;
using etsai::phoenix::Object;
using etsai::phoenix::Actor;

class AllegroActor : public Actor {
public:
    AllegroActor(int xPos, int yPos) : Actor(xPos, yPos) { this->width=5; this->height= 20; }

    virtual void draw() {
        al_draw_filled_rectangle(xPos, yPos, xPos + width, yPos + height, al_map_rgb(0,255,0));
    }

    virtual void tick(double delta) {
        Object::tick(delta);
        yPos-= 90.0 * delta;
        destroy= yPos < 0;
    }
private:
    int width, height;
};

int main(int argc, char **argv) {
    int width= atoi(argv[1]), height= atoi(argv[2]);
    Actor* test= new AllegroActor(100, height-20);

    if(!al_init()) {
        cerr << "failed to initialize allegro!" << endl;
        return -1;
    }
    al_init_primitives_addon();
    ALLEGRO_DISPLAY *display= al_create_display(width, height);
    ALLEGRO_EVENT_QUEUE *event_queue= al_create_event_queue();
    ALLEGRO_TIMER *timer= al_create_timer(1.0/30.0);
    ALLEGRO_EVENT ev;

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_start_timer(timer);
    do {
        al_wait_for_event(event_queue, &ev);

        al_clear_to_color(al_map_rgb(0,0,0));
        Object::tickObjects(1.0/30.0);
        Actor::drawActors();
        al_flip_display();
    } while(ev.type != ALLEGRO_EVENT_DISPLAY_CLOSE);

    al_destroy_display(display);
    return 0;
}