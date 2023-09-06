SHELL := /bin/bash
CXX := g++
INC := ../utility
CXXFLAGS := -g -std=c++14 -Wall -Werror=return-type  -Werror=uninitialized \
			-Wno-sign-compare
LFLAGS := # linking flags
HEADERS := $(wildcard *.hpp)
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)
TARGETS := $(basename $(SRCS))
RM := rm -rf

.PHONY: clean

all: $(TARGETS)

$(TARGETS): %: %.o
	$(CXX) $(LFLAGS) -o $@ $^

$(OBJS): %.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INC:%=-I%) -c -o $@ $<

ll-sort-test.o: ll-sort-test.cpp $(HEADERS)

clean:
	$(RM) $(TARGETS) $(OBJS) *.gc* *.dSYM
