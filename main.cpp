#include "Phoenix/Allegro5/A5HumanPawn.h"
#include "Phoenix/Allegro5/A5SingleProj.h"
#include "Phoenix/Core/Object.h"
#include "Phoenix/Core/HitBox.h"
#include "Phoenix/Core/Actor.h"
#include "Phoenix/Game/HumanPawn.h"
#include "Phoenix/Game/Weapon.h"

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"

#include <ctime>
#include <iostream>
#include <string>
#include <unordered_set>

#define PI 3.141592653589793238462643383279502

using std::cout;
using std::cerr;
using std::endl;
using std::get;
using std::make_pair;
using std::string;
using std::unordered_set;
using namespace etsai::phoenix;

class WeaponImpl : public Weapon {
public:
    WeaponImpl() : Weapon() {
        ammo= 100;
        maxAmmo= 100;
        fireRate= 1;
        cooldown= 0.0;
        index= 0;
    }

    virtual void doFireEffect() {
        cerr << "Fire!" << " (" << ammo << ") (" << clock() << ")" << endl;
    }
    virtual void consumeAmmo() {
        ammo--;
    }
    virtual void draw() {
    }
};

class A5HumanPawnImpl : public A5HumanPawn {
public:
    A5HumanPawnImpl(float xPos, float yPos) : A5HumanPawn(xPos, yPos) {
        Weapon* defaultWeapon= new WeaponImpl();
        weapons.insert(make_pair(defaultWeapon->getWeaponIndex(), defaultWeapon));
        currentWeapon= weapons.begin();
    }
    virtual void touch(Actor *actor) { al_draw_filled_circle(xPos, yPos, 10.0, al_map_rgb(255, 0, 0));}
    virtual void tick(double delta) {
        A5HumanPawn::tick(delta);
        rotate(PI/180.0);
    }
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
    if(!al_install_mouse()) {
        cerr << "failed to initialize the mouse!" << endl;
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
    A5SingleProj *proj= new A5SingleProj(640, 360, PI/2);
    unordered_set<int> downKeys;

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());
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
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                if ((ev.mouse.button & 0x1) == 0x1) {
                    test->startFiring();
                }
                break;
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
                if ((ev.mouse.button & 0x1) == 0x1) {
                    test->stopFiring();
                }
                break;
        }
        al_clear_to_color(al_map_rgb(0,0,0));
        Object::drawObjects();
        test->checkCollisions();
        al_flip_display();
    } while(ev.type != ALLEGRO_EVENT_DISPLAY_CLOSE);

    al_destroy_display(display);
    return 0;
}