CC = gcc
LD = gcc
AR = ar
CFLAGS = -O0 -ggdb3 -fvar-tracking -Wall -Wextra -Wno-unused-parameter \
 -Wshadow -Werror -I./include -I./samples/tigr
LDFLAGS = -L./lib -L./samples/tigr -mwindows
LIBS = -ltzing -ltigr -ld3d9
ARFLAGS = rcs

all: lib/libtzing.a samples/AabbToAabb.exe

lib/libtzing.a: obj/tzing.o lib/
	$(AR) $(ARFLAGS) lib/libtzing.a obj/tzing.o

samples/AabbToAabb.exe: lib/libtzing.a obj/AabbToAabb.o bin/
	$(LD) $(LDFLAGS) -o bin/AabbToAabb.exe obj/AabbToAabb.o $(LIBS)
    
obj/tzing.o: obj/ src/tzing.c src/tzing_internal.h include/tzing.h
	$(CC) $(CFLAGS) -o obj/tzing.o -c src/tzing.c
    
obj/AabbToAabb.o: src/tzing.c src/tzing_internal.h include/tzing.h \
 samples/AabbToAabb.c 
	$(CC) $(CFLAGS) -o obj/AabbToAabb.o -c samples/AabbToAabb.c
    
obj/:
	mkdir obj
    
lib/:
	mkdir lib
    
bin/:
	mkdir bin
    
clean:
	rm -r -f ./obj
	rm -r -f ./lib
	rm -r -f ./bin
    
remake: clean all