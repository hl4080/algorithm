#!/bin/bash
CXX = g++
LDFLAGS = -std=c++14
TARGET = main
#CPP_FILES = $(shell find . -name "*.cpp")
CPP_FILES = $(shell  find ./leetcode ./test/ ./util main.cpp -name "*.cpp")
DATASTRUCT_HEAD = leetcode/data-struct.h
BASE = $(basename $(CPP_FILES))
OBJS = $(addsuffix .o, $(addprefix obj/, $(BASE)))
$(TARGET): $(OBJS)
	-rm -f $@
	$(CXX) $(LDFLAGS) $(OBJS) -o $(TARGET)
obj/%.o: %.cpp $(DATASTRUCT_HEAD)
	@if test ! -d $(basename $@); then\
		mkdir -p $(basename $@);\
		rm -rf $(basename $@);\
	fi
	$(CXX) -c $(LDFLAGS) $< -o $@
clean:
	-rm -f $(TARGET) $(shell find ./obj -name "*.o")
