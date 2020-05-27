#include <iostream>
#include "game.h"

using namespace std;

int main()
{
	Game play;
	std::cout << "Welcome in TicTacToe game " << std::endl;
	std::cout << " ***********************" << std::endl;
	play.play();

	return 0;
}