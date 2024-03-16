CXX:= g++

FLAGS:= -std=c++17 
#-Wall -g -Wextra -pedantic -O2
# FLAGS+= -fsanitize=address

MAIN:= test/main.cpp
TARGET:= ./bin/prog
INCLUDES:= -I../../include
LIBS:= -lSDL2
SRC:= $(wildcard  *.cpp )

all:
	$(CXX)  $(MAIN) $(SRC) $(INCLUDES) $(LIBS) -o $(TARGET) && $(TARGET)

val:
	valgrind $(TARGET)
