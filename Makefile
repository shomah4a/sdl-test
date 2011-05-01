
CC=g++
STD=--std=c++0x
LINKLIBS=-lSDL -lGL -lboost_thread
INCDIR=-Iinclude
CFLAGS=-Wall
TARGETS=main
SRCS=src/main.cpp src/glsupport.cpp
OBJS=$(SRCS:.cpp=.o)

all: $(TARGETS) $(OBJS)


$(TARGETS): $(OBJS)
	$(CC) -o $@ $(OBJS) $(STD) $(CFLAGS) $(INCDIR) $(LINKLIBS)

.cpp.o:
	$(CC) -o $(<:.cpp=.o) -c $< $(STD) $(CFLAGS) $(INCDIR)


clean:
	rm -rf main
	rm -rf $(OBJS)

