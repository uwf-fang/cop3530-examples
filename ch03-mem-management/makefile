TARGETS = c-arrays ref-pointer grid-driver
CXXFLAGS = -Wall
RM = rm

.PHONY: all clean

all : $(TARGETS)

$(TARGETS) : % : %.o
	g++ -o $@ $<

%.o : %.cpp
	g++ -c -o $@ $< $(CXXFLAGS)

grid-driver : grid-driver.o grid.o
	g++ -o $@ $^ $(CXXFLAGS)

grid-driver.o : grid-driver.cpp grid.hpp
	g++ -c -o $@ $<

grid.o : grid.cpp grid.hpp
	g++ -c -o $@ $<

clean :
	$(RM) -f $(TARGETS) *.o