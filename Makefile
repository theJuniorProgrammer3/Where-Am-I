
TARGET = wai

SRC = main.cpp

ifeq ($(OS),Windows_NT)
    CXX = g++
    CXXFLAGS = -std=c++11
    LIBS = -lpdcurses
else
    UNAME_S := $(shell uname -s)
    CXX = g++
    CXXFLAGS = -std=c++11
    LIBS = -lncurses
endif

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LIBS)

clean:
	rm -f $(TARGET)
