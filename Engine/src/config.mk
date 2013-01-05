M_DIR=Engine
M_SRCS=Actor.cpp HitBox.cpp Projectile.cpp Weapon.cpp
SRCS:= $(SRCS) $(addprefix $(M_DIR)/src/,$(M_SRCS))
