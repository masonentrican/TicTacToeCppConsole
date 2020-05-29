#include <iostream>
#include "GameManager.h"


/*
	Starts a fresh game
*/
int GameManager::gameLoop() {

	while (!_isGameOver) {
		int selection;

		drawBoard();
		std::cout << std::endl;
		std::cout << "Player " << _activePlayer << " turn. Enter a number: ";
		std::cin >> selection;

		// Attempt to set the selection to the proper icon
		setGridSlot(selection);

		// Check if a player has won
		checkForWin();

		togglePlayer();

		// End game if winner is found
		if (_winner != 0)
		{
			_isGameOver = true;
		}

	}

	// Game Over
	system("cls");

	std::cout << "Game is over! Player " << _winner << " wins!" << std::endl;
	return 0;
}

/*
	Draws the board
*/
void GameManager::drawBoard() {
	system("cls");

	std::cout << "Player 1 (X)   -   Player 2 (O)" << std::endl << std::endl;
	std::cout << "    |     |" << std::endl;
	std::cout << "  " << _grid[1] << " |  " << _grid[2] << "  | " << _grid[3] << std::endl;
	std::cout << "____|_____|____" << std::endl;
	std::cout << "    |     |" << std::endl;
	std::cout << "  " << _grid[4] << " |  " << _grid[5] << "  | " << _grid[6] << std::endl;
	std::cout << "____|_____|____" << std::endl;
	std::cout << "    |     |" << std::endl;
	std::cout << "  " << _grid[7] << " |  " << _grid[8] << "  | " << _grid[9] << std::endl;
	std::cout << "    |     |" << std::endl;
}

/*
	Checks to see if a player has won
*/
void GameManager::checkForWin() {
	// For each win condition
	for (int x = 0; x < 8; x++) {
		if (_grid[_winCondition[x][0]] == _grid[_winCondition[x][1]] && _grid[_winCondition[x][1]] == _grid[_winCondition[x][2]]) {
			_winner = _activePlayer;
		}
	}
}

/*
	Set a grid slot with checks
*/
void GameManager::setGridSlot(int gridId) {
	if (_grid[gridId] == 'X' || _grid[gridId] == 'O') {
		// Toggle player before redrawing as redraw switches player and we want to end up with the same current player
		togglePlayer();
	}
	else {
		if (_activePlayer == 1)
			_grid[gridId] = 'X';

		if (_activePlayer == 2)
			_grid[gridId] = 'O';
	}
		
}

/*
	Toggle current player
*/
void GameManager::togglePlayer() {
	if (_activePlayer == 1)
		_activePlayer = 2;
	else {
		_activePlayer = 1;
	}
}