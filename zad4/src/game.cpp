#include <iostream>
#include <sstream>
#include <iomanip>
#include "game.h"

Game::Game()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			grid[i][j] = ' ';
		}
	}
}

void Game::printGrid()
{
	std::cout << "    1     2     3" << endl;
	std::cout << " -------------------";
	for (int i = 0; i < 3; i++)
	{
		std::cout << '\n'
				  << to_string(i + 1) << "|";
		for (int j = 0; j < 3; j++)
		{
			std::cout << setw(3) << grid[i][j] << setw(3) << " |";
		}
		std::cout << '\n'
				  << " -------------------";
	}
	cout << std::endl;
}

bool Game::gameOver()
{
	if (ifWin(HUMAN))
		return true;
	else if (ifWin(CPU))
		return true;

	bool emptySpace = false;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (grid[i][j] == ' ')
				emptySpace = true;
		}
	}
	return !emptySpace;
}

bool Game::ifWin(Player player)
{
	char playerChar;
	if (player == HUMAN)
		playerChar = human;
	else
		playerChar = cpu;

	for (int i = 0; i < 3; i++)
	{
		if (grid[i][0] == playerChar && grid[i][1] == playerChar && grid[i][2] == playerChar)
			return true;

		if (grid[0][i] == playerChar && grid[1][i] == playerChar && grid[2][i] == playerChar)
			return true;
	}

	if (grid[0][0] == playerChar && grid[1][1] == playerChar && grid[2][2] == playerChar)
	{
		return true;
	}
	else if (grid[0][2] == playerChar && grid[1][1] == playerChar && grid[2][0] == playerChar)
	{
		return true;
	}

	return false;
}

int Game::score()
{
	if (ifWin(HUMAN))
	{
		return 10;
	}
	else if (ifWin(CPU))
	{
		return -10;
	}
	return 0;
}

Move Game::minimax(char CPUgrid[][3])
{

	int bestMoveScore = 100;
	Move bestMove;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (CPUgrid[i][j] == ' ')
			{
				CPUgrid[i][j] = cpu;
				int tempMoveScore = max(CPUgrid);
				if (tempMoveScore <= bestMoveScore)
				{
					bestMoveScore = tempMoveScore;
					bestMove.x = i;
					bestMove.y = j;
				}
				CPUgrid[i][j] = ' ';
			}
		}
	}

	return bestMove;
}

int Game::max(char CPUgrid[][3])
{
	Move move;
	if (gameOver())
		return score();

	int bestMoveScore = -1000;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (CPUgrid[i][j] == ' ')
			{
				CPUgrid[i][j] = human;
				int tempMoveScore = min(CPUgrid);
				if (tempMoveScore >= bestMoveScore)
				{
					bestMoveScore = tempMoveScore;
					move.x = i;
					move.y = j;
				}
				CPUgrid[i][j] = ' ';
			}
		}
	}

	return bestMoveScore;
}

int Game::min(char CPUgrid[][3])
{
	if (gameOver())
		return score();
	Move move;

	int moveScore = 1000;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (CPUgrid[i][j] == ' ')
			{
				CPUgrid[i][j] = cpu;
				int tempMove = max(CPUgrid);
				if (tempMove <= moveScore)
				{
					moveScore = tempMove;
					move.x = i;
					move.y = j;
				}
				CPUgrid[i][j] = ' ';
			}
		}
	}

	return moveScore;
}

void Game::getHumanMove()
{
	int x, y = -1;
	while (x < 0 || x > 3 || y < 0 || y > 3 || grid[x][y] != ' ')
	{

		std::cout << "Enter your move form: 1 2." << std::endl;
		std::cout << "Your Move: ";
		cin >> x >> y;
		x--;
		y--;
	}
	if (grid[x][y] == ' ')
		grid[x][y] = human;
	else
		std::cout << "This pole is occupied.Try again" << std::endl;
}

void Game::play()
{
	int turn = 0;
	printGrid();
	while (!ifWin(HUMAN) && !ifWin(CPU) && !gameOver())
	{
		if (turn % 2 == 0)
		{
			getHumanMove();
			if (ifWin(HUMAN))
				std::cout << "You Win" << std::endl;
			turn++;
			printGrid();
		}
		else
		{
			std::cout << std::endl
					  << "Computer Move:" << std::endl;
			Move CPUmove = minimax(grid);
			grid[CPUmove.x][CPUmove.y] = cpu;
			if (ifWin(CPU))
				std::cout << "Computer Wins" << std::endl;
			turn++;
			printGrid();
		}
		if(!ifWin(HUMAN) && !ifWin(CPU) && gameOver())
		std::cout <<"It's a draw "<< std::endl;
		
	}
}