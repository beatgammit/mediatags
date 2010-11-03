CC_FLAGS = -Wall -Werror
LD_FLAGS = -l id3

all:
	$(CXX) $(CC_FLAGS) -o id3tags $(LD_FLAGS) id3tags.cpp
.PHONY: all
