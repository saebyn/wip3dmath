CPP = g++
CPPFLAGS = -I.. -Wall -Wold-style-cast -Woverloaded-virtual -pedantic -L.. -lwip3dmath -lgtest_main -pthread

OBJECTS := $(patsubst %.cc, %, $(wildcard *.cc))

.SUFFIXES:
.SUFFIXES:      .o .cc

all : $(OBJECTS)
	./$<

.cc : $(wildcard *.cc)
	$(CPP) $(CPPFLAGS) -o $@ $<

.PHONY: clean
clean :
	rm -f $(OBJECTS)

