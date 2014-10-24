# Takes the name of the current directory as a the executable and "pr" name
TARGET  := $(shell basename $$PWD)
# Compiler
CC      := gcc
# Warning levels
WARN    :=
# Optimisation
OFLAGS  := 
# Aditionnal libraries to link
LDFLAGS := 

CPP_SRCS    = $(wildcard src/*.cpp)
OBJ_FILES   = $(CPP_SRCS:.cpp=.o)

%o: src/%.cpp 
	@echo "Compiling "$<"..."
	$(CC) -c $(WARN) $(OFLAGS) $< -o $@

$(TARGET): $(OBJ_FILES)
	@echo "Linking..."
	$(CC) $(WARN) $(OFLAGS) -o $@ $(OBJ_FILES) $(LDFLAGS) 
	@echo "Done."

all: ${TARGET}

clean: 
	@echo "Cleaning..."
	rm -rf ./src/*.o

mrproper: clean
	rm -rf ${TARGET}

install: all
	@echo "Installing..."
	install homesay /usr/bin
	cp -rf homecows /usr/share

uninstall:
	@echo "Uninstalling..."
	rm -rf /usr/share/homecows
	rm -rf /usr/bin/homesay
