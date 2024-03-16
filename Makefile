CXX:= g++

FLAGS:= -std=c++17 
#-Wall -g -Wextra -pedantic -O2
# FLAGS+= -fsanitize=address

TARGET:= ./bin/prog

SRC:= $(wildcard ./src/*.cpp ./src/**/*.cpp ./src/**/**/*.cpp)

SMALL_SRC = $(wildcard ./src/*.cpp ./src/game/*.cpp ./src/engine/*.cpp \
 ./src/entity/*.cpp \
./src/level/*.cpp  ./src/game_state/*.cpp ./src/scene/*.cpp)

APP_SRC = $(wildcard ./src/test/*.cpp)

INCLUDE:= -I./include -I./third_party/include 
LIBS:= -lSDL2 -lSDL2_ttf 
LIBS+= -ldl

GLAD:= ./third_party/include/glad/glad/glad.o

all:
	$(CXX) $(SRC) $(FLAGS) $(INCLUDE) $(LIBS) -o $(TARGET) && $(TARGET)

engine:
	$(CXX) $(SMALL_SRC) $(FLAGS) $(GLAD) $(INCLUDE) $(LIBS) -o $(TARGET) && $(TARGET)

test:
	$(CXX) $(APP_SRC) $(FLAGS) $(LIBS)  -o $(TARGET) && $(TARGET)


run:
	$(TARGET)

val:
	valgrind $(TARGET)

valf:
	valgrind --show-leak-kinds=all --track-origins=yes --leak-check=full -v --log-file="valgrind.txt" $(TARGET) 


valc:
	valgrind --tool=cachegrind $(TARGET) 10000000

## prereq
glad.o:
	$(CXX) $(FLAGS) -c ./third_party/include/glad/glad.c  \
	-I ./third_party/include/glad/ \
	-o ./third_party/include/glad/glad/glad.o

