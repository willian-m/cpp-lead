all: programs

programs: ProgressBarExample

# define compiler/linker flags
CXX       = g++

CXXFLAGS  = -O3 -Wall -fPIC -std=c++17
CXXFLAGS += -I$(PWD)/include

ProgressBarExample: example/main.cpp include/ProgressBar.hpp
	$(CXX) $(CXXFLAGS)  $^ -o $@

.PHONY: clean distclean

# remove object files
clean:
	@rm -f *.o ProgressBarExample

# remove objects, libraries and dicts
distclean: clean
	@rm -f *.o ProgressBarExample

