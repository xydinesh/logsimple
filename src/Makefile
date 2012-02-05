CC=gcc
CFLAGS= -O3
# include directories
INCLUDES =

.SUFFIXES: .cpp

.cpp.o:
	$(CC) $(CFLAGS) -c $< $(INCLUDES)

.cpp :
	$(CC) $(CFLAGS) $< -o $@ 

# source
SRC = log.c
# source files.
OUT=liblogsimple.a
OBJ = $(addsuffix .o, $(basename $(SRC)))

all: $(OUT)

$(OUT): $(OBJ)
	ar -rv -o $@ $^

clean:
	rm -f *.o \#* PI* core* *~ $(OBJ) $(OUT)

# makefile tutorial: http://www.cs.duke.edu/~ola/courses/programming/Makefiles/node1.html

