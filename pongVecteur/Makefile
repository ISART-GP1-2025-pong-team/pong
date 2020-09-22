
CC?=gcc
TARGET?=$(shell $(CC) -dumpmachine)

CFLAGS=-Wall -g -O0 -fPIC -I../externals/include
CPPFLAGS=-MMD

ifeq ($(OS),Windows_NT)
LDFLAGS=-L../externals/$(TARGET)/libs
LDLIBS=-lgpdll -lglfw3dll -lgdi32 -lglu32
else
LD_LIBRARY_PATH=../externals/$(TARGET)/libs
LDFLAGS+=-L../externals/$(TARGET)/bin -Wl,-rpath,$(LD_LIBRARY_PATH)
LDLIBS=-lgp -lglfw
endif

OBJS=src/main.o src/game.o src/game_functions.o src/vector2.o src/intersection.o
DEPS=$(OBJS:.o=.d)

.PHONY: all clean

all: pong run

-include $(DEPS)

pong: $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@

run: pong
	PATH=$$PATH:../externals/$(TARGET)/bin ./$<

clean:
	rm -f $(OBJS) $(DEPS) pong:q

