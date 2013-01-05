include config.mk

%.o: %.cpp
	$(CPPC) -c $(CPP_FLAGS) $< -o $@

all: setup $(OBJS)
	$(CPPC) $(CPP_FLAGS) $(MAIN) -o $(MAIN_OBJ) $(OBJS) `pkg-config --cflags --libs $(ALLEGRO_LIBS)`
	cp -R Textures $(DIST)/.

setup:
	if [ ! -e $(DIST) ]; then \
	    mkdir $(DIST); \
	fi


clean:
	rm -rf $(OBJS) $(MAIN_OBJ) $(DIST)

doc: setup
	doxygen
