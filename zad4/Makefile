CXX		  := g++
CXX_FLAGS := -Wall -pedantic -Wextra -std=c++17 -ggdb

BIN		:= bin
SRC		:= src
INCLUDE	:= inc
LIB		:= lib

LIBRARIES	:= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network
EXECUTABLE	:= tictactoe


all: $(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

clean:
	-rm $(BIN)/*

val:
	valgrind --tool=memcheck --leak-check=full ./$(NAME)
