CXX = g++
#CXXFLAGS = -std=c++11 -Wall -Wextra -Werror -pedantic -O3
CXXFLAGS = -std=c++17 -O3

%.x: %.o
	$(CXX) $(CXXFLAGS) -o $@ $<

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f *.o *.x *.out
