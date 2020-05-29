#pragma once
#include <vector>

class GameManager
{
private:
	bool _isGameOver = false;
	int _activePlayer = 1;
	int _round = 0;
	int _winner = 0;
	char _grid[10] = { 'o','1','2','3','4','5','6','7','8','9' };
	int _winCondition[8][3]{
		{1,2,3},
		{4,5,6},
		{7,8,9},
		{1,4,7},
		{2,5,8},
		{3,6,9},
		{1,5,9},
		{7,5,3}
	};

public:
	int gameLoop();
	void drawBoard();
	void checkForWin();
	void setGridSlot(int gridId);
	void togglePlayer();
};