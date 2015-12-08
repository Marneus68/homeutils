# Takes the name of the current directory as a the executable and "pr" name
TARGET  := $(shell basename $$PWD)
# Warning levels
WARN    :=
# Optimisation
OFLAGS  := -std=c++11
# Aditionnal libraries to link
LDFLAGS := 

CPP_SRCS    = $(wildcard src/*.cpp)
OBJ_FILES   = $(CPP_SRCS:.cpp=.o)

homespeak: src/homespeak.cpp
	@echo "Compiling "$<".."
	$(CXX) $(OFLAGS) $(WARN) $< -o $@

all: homespeak

clean: 
	@echo "Cleaning..."
	rm -rf ./src/*.o

mrproper: clean
	rm -rf homespeak

install: all
	@echo "Installing..."
	install homesay /usr/bin
	install homespeak /usr/bin
	cp -rf homecows /usr/share

uninstall:
	@echo "Uninstalling..."
	rm -rf /usr/share/homecows
	rm -rf /usr/bin/homesay
	rm -rf /usr/bin/homespeak
