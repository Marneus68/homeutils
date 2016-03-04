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

# Colors
black	= `tput setaf 0`
red		= `tput setaf 1`
green	= `tput setaf 2`
yellow	= `tput setaf 3`
blue	= `tput setaf 4`
magenta = `tput setaf 5`
cyan	= `tput setaf 2`
white	= `tput setaf 7`
reset	= `tput sgr0`

all: homespeak

homespeak: src/homespeak.cpp
	@echo "$(blue)Compiling $(yellow)"$<"$(blue)...$(reset)"
	$(CXX) $(OFLAGS) $(WARN) $< -o $@
	@echo "$(green)Done.$(reset)"

clean: 
	@echo "$(blue)Cleaning objects...$(reset)"
	rm -rf ./src/*.o

mrproper: clean
	@echo "$(blue)Cleaning executables...$(reset)"
	rm -rf homespeak

install: all
	@echo "$(blue)Installing...$(reset)"
	install homesay /usr/bin
	install homespeak /usr/bin
	cp -rf homecows /usr/share
	@echo "$(green)Done.$(reset)"

uninstall:
	@echo "$(blue)Uninstalling...$(reset)"
	rm -rf /usr/share/homecows
	rm -rf /usr/bin/homesay
	rm -rf /usr/bin/homespeak
	@echo "$(green)Done.$(reset)"
