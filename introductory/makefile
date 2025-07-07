# Makefile

CXX = g++-15
CXXFLAGS = -std=c++11 -O2 -Wall

# Require FILE variable, fail if not set
ifndef FILE
$(error Please specify the source file: make FILE=your_code.cpp)
endif

TARGET = $(basename $(FILE))

all:
	$(CXX) $(CXXFLAGS) $(FILE) -o $(TARGET)

clean:
	rm -f $(TARGET)