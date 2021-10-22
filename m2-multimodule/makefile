TARGETS = main
CXXFLAGS = -Wall
RM = rm

all : $(TARGETS)

main : main.o threeintsfcts.o
	g++ -o main main.o threeintsfcts.o

main.o : main.cpp threeintsfcts.h
	g++ -Wall -c main.cpp

threeintsfcts.o : threeintsfcts.h threeintsfcts.cpp
	g++ -Wall -c threeintsfcts.cpp

clean :
	$(RM) -f $(TARGETS) *.o