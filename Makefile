CPP = g++
LD = g++
AR = ar
CPPFLAGS = -fPIC -O3 -Wall -I.
LDFLAGS = -shared -fPIC -O3
INSTALL_DIR = ..

objects = Rotation/Euler/Euler.o \
          Rotation/Quaternion/Quaternion.o \
          Point/Point.o \
          UnitVector/UnitVector.o \
          UnitVector/Vector/Vector.o \
          Volume/Box/Box.o \
          Volume/Cylinder/Cylinder.o \
          Bezier/BezierSurface/BezierSurface.o \
          QuadTree/QuadTree.o \
          MathUtils.o \
          Matrix.o \
          IO.o

all: libwip3dmath.so

libwip3dmath.so:    $(objects)
	$(LD) -shared $(LDFLAGS) $(objects) -o libwip3dmath.so

%.o:    %.cc
	$(CPP) -c $(CPPFLAGS) $< -o $@

.PHONY: clean
clean :
	rm -f $(objects)
	rm -f libwip3dmath.a
	rm -f libwip3dmath.so
	rm -f *~
