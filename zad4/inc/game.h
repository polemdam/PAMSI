#include <iostream>
using namespace std;

enum Player
{
	HUMAN,
	CPU
};

struct Move
{
	int x;
	int y;
};

class Game
{
private:
	char grid[3][3];
	const char human = 'X';
	const char cpu = 'O';

public:
	Game();
	~Game(){};
	void printGrid();

	bool gameOver();
	bool ifWin(Player player);
	void getHumanMove();
	int score();
	Move minimax(char CPUboard[][3]);
	int min(char CPUboard[][3]);
	int max(char CPUboard[][3]);
	void play();
};
