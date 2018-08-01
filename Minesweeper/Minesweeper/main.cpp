#include <iostream>

#include "Minesweeper.h"

int main(int argc, const char * argv[]) {
	
	MinesweeperGame minesweeper(20, 20);
	
	minesweeper.checkForBombs();
	
    return 0;
}
