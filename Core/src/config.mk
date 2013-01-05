M_DIR=Core
M_SRCS=Common.cpp Object.cpp
SRCS:= $(SRCS) $(addprefix $(M_DIR)/src/,$(M_SRCS))
