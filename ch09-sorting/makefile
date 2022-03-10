# This makefile is designed to compile single target multi-file projects

CXX = g++
CXXFLAGS = -std=c++11 -Wall -g # compilation flags
LFLAGS =  # linking flags
TARGET = sorting-test
HEADERS = llist.hpp
SRCS = sorting-test.cpp
OBJS = sorting-test.o
RM = rm -rf

.PHONY: clean

$(TARGET): $(OBJS)
	$(CXX) $(LFLAGS) -o $@ $^

$(OBJS): %.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	$(RM) $(TARGET) $(OBJS)