CXX=clang++-9 
CXXFLAGS=-std=c++2a -Werror

HEADERS=life.hpp
OBJECTS=life.o
SOURCES=life.cpp

run: main
	./$^

main: main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o main

# test: TestCounter.o Test.o $(OBJECTS)
# 	$(CXX) $(CXXFLAGS) $^ -o test

# tidy:
# 	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-* --warnings-as-errors=-* --

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o main