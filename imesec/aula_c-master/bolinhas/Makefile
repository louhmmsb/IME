CC ?= cc
CFLAGS += -g $(shell pkg-config --cflags sdl2)
LDLIBS += $(shell pkg-config --libs sdl2)

OBJ := graphic.o free.o
BIN := visualizer

all : $(BIN)

%.o : %.c
	        $(CC) $(CFLAGS) -c -o $@ $<

$(BIN) : $(OBJ)
	        $(CC) -o $@ $^ $(LDLIBS)

clean:
	        rm -f $(OBJ) $(BIN)
