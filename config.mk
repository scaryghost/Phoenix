CPPC=g++
INC_DIR=..
MAIN_OBJ=phoenix
MAIN=main.cpp
SRCS:=

MODULES=Core\
    Game
ALLEGRO_LIBS=allegro-5.0 allegro_font-5.0 allegro_ttf-5.0 allegro_primitives-5.0 allegro_image-5.0

MODULE_CONFIG= $(foreach module, $(MODULES), $(module)/src/config.mk)

include $(MODULE_CONFIG)

CPP_FLAGS=-Wall -std=c++0x -I$(INC_DIR) 
OBJS= $(patsubst %.cpp, %.o, $(SRCS))
