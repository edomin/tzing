CC = gcc
LD = gcc
AR = ar
CFLAGS = -O0 -ggdb3 -fvar-tracking -Wall -Wextra -Wno-unused-parameter \
 -Wshadow -Werror -I./include -I./samples/tigr
LDFLAGS = -L./lib -L./samples/tigr -mwindows
LIBS = -ltzing -ltigr -ld3d9
ARFLAGS = rcs

.PHONY: all

all: prebuild lib/libtzing.a bin/AabbToAabb.exe

# Library

lib/libtzing.a: obj/tzing.o
	$(AR) $(ARFLAGS) lib/libtzing.a obj/tzing.o
    
obj/tzing.o: src/tzing.c src/tzing_internal.h include/tzing.h
	$(CC) $(CFLAGS) -o obj/tzing.o -c src/tzing.c

# Tigr (needed for samples)
    
samples/tigr/libtigr.a: samples/tigr/tigr.o
	$(AR) $(ARFLAGS) samples/tigr/libtigr.a samples/tigr/tigr.o
    
samples/tigr/tigr.o:
	$(CC) $(CFLAGS) -Wno-error -o samples/tigr/tigr.o -c samples/tigr/tigr.c
    
# Samples
    
bin/AabbToAabb.exe: lib/libtzing.a obj/AabbToAabb.o samples/tigr/libtigr.a
	$(LD) $(LDFLAGS) -o bin/AabbToAabb.exe obj/AabbToAabb.o $(LIBS)
    
bin/PointToCircle.exe: lib/libtzing.a obj/PointToCircle.o samples/tigr/libtigr.a
	$(LD) $(LDFLAGS) -o bin/PointToCircle.exe obj/PointToCircle.o $(LIBS)
    
obj/AabbToAabb.o: src/tzing.c src/tzing_internal.h include/tzing.h \
 samples/AabbToAabb.c 
	$(CC) $(CFLAGS) -o obj/AabbToAabb.o -c samples/AabbToAabb.c
    
obj/PointToCircle.o: src/tzing.c src/tzing_internal.h include/tzing.h \
 samples/PointToCircle.c 
	$(CC) $(CFLAGS) -o obj/PointToCircle.o -c samples/PointToCircle.c
    
prebuild:
	-mkdir obj
	-mkdir lib
	-mkdir bin
    
clean:
	rm -r -f ./obj
	rm -r -f ./lib
	rm -r -f ./bin
	rm -r -f ./samples/tigr/tigr.o
	rm -r -f ./samples/tigr/libtigr.a
    
remake: clean all
