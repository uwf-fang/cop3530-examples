CXXFLAGS = -Wall -std=c++14
RM = rm -rf
TARGETS = test-deque

.PHONY: all clean

test-all : $(TARGETS)

# compile cpp files to object files
%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $<

# link and run all targets
$(TARGETS): % : %.o
	$(CXX) -o $@ $^
	./$@

clean :
	$(RM) $(TARGETS) *.o
