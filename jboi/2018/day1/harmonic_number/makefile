CC=g++
CFLAGS=-Wall -Wshadow -fsanitize=address -fsanitize=undefined -Wshadow -DLOCAL
.SUFFIXES = .cpp
objs:=$(wildcard *.cpp)
targets:=$(objs:.cpp= )

.PHONY:all
all: $(targets)
.cpp:
	$(CC) $(CFLAGS) -std=c++17 -o $@ $< 
