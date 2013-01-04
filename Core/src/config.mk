M_DIR=Core
M_SRCS=Actor.cpp Common.cpp HitBox.cpp Object.cpp
SRCS:= $(SRCS) $(addprefix $(M_DIR)/src/,$(M_SRCS))
