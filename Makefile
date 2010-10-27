LD_FLAGS = -l id3

all:
	$(CXX) -o id3tags $(LD_FLAGS) id3tags.cpp
.PHONY: all
