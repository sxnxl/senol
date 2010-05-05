CXX = mpicc

CXXFLAGS = -O3 -Wall

INCLUDE_DIR = ../../include

SRC_DIR = ../

CXXFLAGS += -I $(INCLUDE_DIR)

all: tests

tests: prep strlen fstrlen

strlen:
		$(CXX) $(CXXFLAGS) -o bin/std/tst-strlen tst-strlen.c $(SRC_DIR)strlen.c

fstrlen: 
		$(CXX) $(CXXFLAGS) -o bin/flibc/tst-strlen tst-strlen.c $(SRC_DIR)strlen.c -DTEST_USING_FSTRING

prep:
		mkdir -p bin/ bin/std/ bin/flibc/
remove:
		rm -rf bin/
