#
# Makefile for CS 70 Spell Checking Assignment
# 

# ----- Make Variables -----

# OPTFLAGS  =   -O2
DEFINES   =
CXXFLAGS  =	-g $(OPTFLAGS) -Wall -Wextra -Wdocumentation -pedantic \
                $(DEFINES) 
CXX	  =	cs70-c++
GTEST_LIB =	-lgtest -lgtest_main

TESTS     =     hashset-cow-test    treeset-cow-test \
                stdhashset-cow-test stdtreeset-cow-test \
                stdtreeset-test     stdhashset-test \
                treeset-test        hashset-test

TARGETS   = 	$(TESTS) myspell

# ----- Make Rules -----

all:	$(TARGETS)

test:	$(TESTS)
	./treeset-cow-test
	./hashset-cow-test
	./stdtreeset-cow-test
	./stdhashset-cow-test
	./stdtreeset-test
	./stdhashset-test
	./treeset-test
	./hashset-test

clean:
	rm -f $(TARGETS) *.o

hashset-cow-test: hashset-cow-test.o cow.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_LIB)

treeset-cow-test: treeset-cow-test.o cow.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_LIB)

stdhashset-cow-test: stdhashset-cow-test.o cow.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_LIB)

stdtreeset-cow-test: stdtreeset-cow-test.o cow.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_LIB)

myspell: myspell.o stringhash.o
	$(CXX) $(CXXFLAGS) -o myspell $^

treeset-test: treeset-test.o 
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_LIB)

hashset-test: hashset-test.o stringhash.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_LIB)

stdtreeset-test: stdtreeset-test.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_LIB)

stdhashset-test: stdhashset-test.o stringhash.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_LIB)
# ------ Dependences (.cpp -> .o using default Makefile rule) -----

cow.o: cow.cpp cow.hpp
generic-set-tests.o: generic-set-tests.cpp
hashset-cow-test.o: hashset-cow-test.cpp hashset.hpp abstractset.hpp \
  hashset-private.hpp cow.hpp cow-tests.hpp
hashset-test.o: hashset-test.cpp stringhash.hpp hashset.hpp \
  abstractset.hpp hashset-private.hpp generic-set-tests.cpp
myspell.o: myspell.cpp myspell.hpp stringhash.hpp treeset.hpp \
  abstractset.hpp treeset-private.hpp hashset.hpp hashset-private.hpp \
  stdtreeset.hpp stdtreeset-private.hpp stdhashset.hpp \
  stdhashset-private.hpp
stdhashset-cow-test.o: stdhashset-cow-test.cpp stdhashset.hpp \
  abstractset.hpp stdhashset-private.hpp cow.hpp cow-tests.hpp
stdhashset-test.o: stdhashset-test.cpp stringhash.hpp stdhashset.hpp \
  abstractset.hpp stdhashset-private.hpp
stdtreeset-cow-test.o: stdtreeset-cow-test.cpp stdtreeset.hpp \
  abstractset.hpp stdtreeset-private.hpp cow.hpp cow-tests.hpp
stdtreeset-test.o: stdtreeset-test.cpp stdtreeset.hpp abstractset.hpp \
  stdtreeset-private.hpp
stringhash.o: stringhash.cpp stringhash.hpp
treeset-cow-test.o: treeset-cow-test.cpp treeset.hpp abstractset.hpp \
  treeset-private.hpp cow.hpp cow-tests.hpp
treeset-test.o: treeset-test.cpp treeset.hpp abstractset.hpp \
  treeset-private.hpp generic-set-tests.cpp
