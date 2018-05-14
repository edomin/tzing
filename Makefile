CC = gcc
LD = gcc
AR = ar
CFLAGS = -O0 -ggdb3 -fvar-tracking -Wall -Wextra -Wno-unused-parameter \
 -Wshadow -Werror -I./include -I./samples -I./samples/tigr
LDFLAGS = -L./lib -L./samples/tigr -mwindows
LIBS = -ltzing -ltigr -ld3d9
ARFLAGS = rcs

.PHONY: all

all: prebuild lib/libtzing.a bin/AabbToAabb.exe bin/PointToAabb.exe \
 bin/PointToCircle.exe

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
    
# Draw helpers (needed for samples)
    
obj/DrawCircle.o: samples/DrawCircle.c samples/DrawCircle.h
	$(CC) $(CFLAGS) -o obj/DrawCircle.o -c samples/DrawCircle.c
    
# Samples
    
bin/AabbToAabb.exe: lib/libtzing.a obj/AabbToAabb.o samples/tigr/libtigr.a
	$(LD) $(LDFLAGS) -o bin/AabbToAabb.exe obj/AabbToAabb.o $(LIBS)
    
bin/PointToAabb.exe: lib/libtzing.a obj/PointToAabb.o samples/tigr/libtigr.a
	$(LD) $(LDFLAGS) -o bin/PointToAabb.exe obj/PointToAabb.o $(LIBS)
    
bin/PointToCircle.exe: lib/libtzing.a obj/PointToCircle.o obj/DrawCircle.o \
 samples/tigr/libtigr.a
	$(LD) $(LDFLAGS) -o bin/PointToCircle.exe obj/PointToCircle.o \
     obj/DrawCircle.o $(LIBS)

obj/AabbToAabb.o: src/tzing.c src/tzing_internal.h include/tzing.h \
 samples/AabbToAabb.c 
	$(CC) $(CFLAGS) -o obj/AabbToAabb.o -c samples/AabbToAabb.c
     
obj/PointToAabb.o: src/tzing.c src/tzing_internal.h include/tzing.h \
 samples/PointToAabb.c 
	$(CC) $(CFLAGS) -o obj/PointToAabb.o -c samples/PointToAabb.c
    
obj/PointToCircle.o: src/tzing.c src/tzing_internal.h include/tzing.h \
 samples/PointToCircle.c samples/DrawCircle.h
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
