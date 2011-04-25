CPP = g++
LD = g++
AR = ar
CPPFLAGS = -fPIC -I. -Wall -Wold-style-cast -Woverloaded-virtual -pedantic
LDFLAGS = -shared -fPIC

SOURCES = Rotation/Euler/Euler.cc \
          Rotation/Quaternion/Quaternion.cc \
          Point/Point.cc \
          UnitVector/UnitVector.cc \
          UnitVector/Vector/Vector.cc \
          Volume/Box/Box.cc \
          Volume/Cylinder/Cylinder.cc \
          Bezier/BezierSurface/BezierSurface.cc \
          QuadTree/QuadTree.cc \
          MathUtils.cc \
          Matrix.cc \
          IO.cc

OBJECTS := $(patsubst %.cc, %.o, $(SOURCES))

all: libwip3dmath.so test

libwip3dmath.so:    $(OBJECTS)
	$(LD) -shared $(LDFLAGS) $(OBJECTS) -o libwip3dmath.so

.SUFFIXES:
.SUFFIXES:      .o .cc

.cc.o : $(SOURCES)
	$(CPP) -c $(CPPFLAGS) -o $@ $<

.PHONY: clean test
clean :
	rm -f $(OBJECTS)
	rm -f libwip3dmath.a
	rm -f libwip3dmath.so
	rm -f *~
	(cd tests && make clean)

test : libwip3dmath.so
	(cd tests && make)
