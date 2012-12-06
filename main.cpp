#include "Phoenix/Core/Object.h"
#include "Phoenix/Core/Actor.h"
#include "Phoenix/Core/Pawn.h"
#include "Phoenix/Core/Controller.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include <iostream>

using std::cerr;
using std::endl;
using namespace etsai::phoenix;

class AllegroPawn : public Pawn {
public:
    AllegroPawn(int xPos, int yPos) : Pawn(xPos, yPos) { this->width= 64; this->height= 64; }

    virtual void draw() {
        al_draw_filled_rectangle(xPos, yPos, xPos + width, yPos + height, al_map_rgb(0,255,0));
    }

private:
    int width, height;
};

int main(int argc, char **argv) {
    int width= atoi(argv[1]), height= atoi(argv[2]);
    Pawn *test= new AllegroPawn(100, 100);

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
                    test->moveYAxis(-1);
                }
                break;
        }
        al_clear_to_color(al_map_rgb(0,0,0));
        Actor::drawActors();
        al_flip_display();
    } while(ev.type != ALLEGRO_EVENT_DISPLAY_CLOSE);

    al_destroy_display(display);
    return 0;
}