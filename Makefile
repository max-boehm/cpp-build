CXX      = g++
CXXFLAGS = -std=c++17 -Wall -g
LDFLAGS  =
LDLIBS   =

all: hello hello_test

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

hello: hello.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

hello_test: hello_test.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS) -lgtest -lgtest_main

clean:
	rm -f hello hello.o hello_test hello_test.o
