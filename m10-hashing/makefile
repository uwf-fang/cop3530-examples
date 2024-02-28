CXXFLAGS = -Wall -std=c++14
RM = rm -rf
TARGETS = test-open

.PHONY: all clean

test-all : $(TARGETS)

# compile cpp files to object files
%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $<

# link and run all targets
$(TARGETS): % : %.o
	$(CXX) -o $@ $^
	./$@

test-open: test-open.o open-addressing.o

clean :
	$(RM) $(TARGETS) *.o
