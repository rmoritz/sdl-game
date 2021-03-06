OBJS := $(wildcard src/*.cc)
CXX := g++
RM := del
INCLUDE_PATHS := -Iinclude
LIBRARY_PATHS := -DDEBUG
OBJ_NAME := game.exe

CXXFLAGS := --std=c++14 -Wall -Wextra -Wstrict-aliasing -pedantic -Wunreachable-code -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wshadow -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wundef -Wno-unused -Wno-variadic-macros -Wno-parentheses -fdiagnostics-show-option -Wl,-subsystem,windows

LDFLAGS := -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

.PHONY: all clean

all : $(OBJS)
	$(CXX) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(CXXFLAGS) $(LDFLAGS) -o $(OBJ_NAME)

clean:
	$(RM) $(OBJ_NAME)
