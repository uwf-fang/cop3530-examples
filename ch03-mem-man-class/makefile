all: test3 test5 test-shallow

test3: rule-of-3.cpp
	g++ -std=c++11 -o $@ $<

test5: rule-of-5.cpp
	g++ -std=c++11 -o $@ $<

test-shallow: shallow-copy.cpp
	g++ -std=c++11 -o $@ $<

clean:
	rm -rf $(all) *.o
