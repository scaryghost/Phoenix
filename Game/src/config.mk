M_DIR=Game
M_SRCS=Dosh.cpp HumanPawn.cpp Single.cpp Double.cpp SingleProj.cpp
SRCS:= $(SRCS) $(addprefix $(M_DIR)/src/,$(M_SRCS))
