SHELL := /bin/bash
CXX := g++
INC := ../utility
CXXFLAGS := -g -std=c++14 -Wall -Werror=return-type  -Werror=uninitialized \
			-Wno-sign-compare
LFLAGS := # linking flags
HEADERS := $(wildcard *.hpp)
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)
TARGETS := test
RM := rm -rf

.PHONY: clean

all: $(TARGETS)

test: $(OBJS)
	$(CXX) $(LFLAGS) -o $@ $^

$(OBJS): %.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(INC:%=-I%) -c -o $@ $<

clean:
	$(RM) $(TARGETS) $(OBJS) *.gc* *.dSYM
