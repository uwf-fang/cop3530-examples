TARGETS = array-params pass-by-ref-pointer object-array
CXXFLAGS = -Wall -std=c++14
RM = rm -rf

.PHONY: all clean

all : $(TARGETS)

$(TARGETS) : % : %.o
	g++ -o $@ $<

%.o : %.cpp
	g++ -c -o $@ $< $(CXXFLAGS)

clean :
	$(RM) $(TARGETS) *.o
