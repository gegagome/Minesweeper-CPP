#include <stdio.h>

#include "Minesweeper.h"

// CONSTRUCTOR
MinesweeperGame::MinesweeperGame(int row, int column): rows(row), columns(column) {
	makeSquare(row, column);
	
//	In case you want to use custom data
//	easyDataInput();
	
//	To check for a specific range
//	cout << checkAdjacentBombs(aSquare, 3, 4) << "<<<<<" << endl;
	display();
}

// PUBLIC

void MinesweeperGame::makeRandomSquare() {
	// TO BE DEVELOPED
}

void MinesweeperGame::makeSquare(const int &row, const int &column) {
	srand (time(NULL));
	for (int i = 0; i < row; i++) {
		vector<char> r;
//		cout << "Let's fill our row # " << i + 1 << " of " << rows << endl;
		for (int j = 0; j < column; j++) {
			
//			Random characters.
			char c = randomChar();
			
//			For user input. Uncomment line above J for loop as well for prompt.
//			char c;
//			cout << "Enter either an asterisk or dot for column # " << j + 1 << " of " << columns << endl;
//			cin >> c;
//			if (c != ASTERISK) {
//				c = DOT;
//			}
			r.push_back(c);
		}
		aSquare.push_back(r);
	}
}

void MinesweeperGame::display() {
	// draw data
	
	cout << endl;
	cout << "------------" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << aSquare[i][j] << "\t";
			if (j == columns - 1) {
				cout << endl;
			}
		}
	}
	cout << "------------" << endl;
	cout << endl;
}

void MinesweeperGame::checkForBombs() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			int result = checkAdjacentBombs(aSquare, i, j);
			if (result != -1) {
				cout << result << "\t";
			} else {
				cout << ASTERISK << "\t";
			}
			if (j == columns - 1) {
				cout << endl;
			}
		}
	}
}

int MinesweeperGame::checkAdjacentBombs(const vector<vector<char> > &v, const int r, const int c) {
	vector <vector <int> > tempVector;
	int minRow = r - 1;
	int maxRow = r + 1;
	int minColumn = c - 1;
	int maxColumn = c + 1;
	int bombs = 0;
	
	if (r == 0) {
		minRow = r;
		maxRow = r + 1;
	}
	
	if (r == rows - 1) {
		minRow = r - 1;
		maxRow = r;
	}
	
	if (c == 0) {
		minColumn = c;
		maxColumn = c + 1;
	}
	
	if (c == columns - 1) {
		minColumn = c - 1;
		maxColumn = c;
	}
	
//	cout << minRow << "," << minColumn << endl;
//	cout << maxRow << "," << maxColumn << endl;
	
	for (int i = minRow; i <= maxRow; i++) {
		for (int j = minColumn; j <= maxColumn; j++) {
			if (checkValue(i, j) == ASTERISK) {
				if (i == r && j == c) {
					return -1;
					break;
				}
				bombs++;
			}
		}
	}
	
	return bombs;
}

char MinesweeperGame::checkValue(const int r, const int c) {
	char ch = aSquare[r][c];
	
	return ch;
}

void MinesweeperGame::easyDataInput() {
	aSquare[0][0] = ASTERISK;
	aSquare[0][1] = DOT;
	aSquare[0][2] = DOT;
	aSquare[0][3] = ASTERISK;
	aSquare[0][4] = DOT;
	
	aSquare[1][0] = DOT;
	aSquare[1][1] = DOT;
	aSquare[1][2] = DOT;
	aSquare[1][3] = DOT;
	aSquare[1][4] = DOT;
	
	aSquare[2][0] = ASTERISK;
	aSquare[2][1] = DOT;
	aSquare[2][2] = ASTERISK;
	aSquare[2][3] = DOT;
	aSquare[2][4] = ASTERISK;
	
	aSquare[3][0] = DOT;
	aSquare[3][1] = ASTERISK;
	aSquare[3][2] = DOT;
	aSquare[3][3] = ASTERISK;
	aSquare[3][4] = DOT;
}

char MinesweeperGame::randomChar() {
	int r = rand() % 101;
	
	return (r < bombRatio) ? DOT : ASTERISK;
}
