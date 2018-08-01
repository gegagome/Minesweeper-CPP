#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MinesweeperGame {
public:
	MinesweeperGame(int, int);
	void makeRandomSquare();
	void makeSquare(const int &row, const int &column);
	void display();
	void checkForBombs();
	
private:
	const char ASTERISK = '*';
	const char DOT = '.';
	const int bombRatio = 70;;
	int rows = 0;
	int columns = 0;
	int totalBombs = 0;
	vector<vector <char> > aSquare;
	
	char checkValue(const int r, const int c);
	int checkAdjacentBombs(const vector<vector<char> > &v, const int r, const int c);
	void easyDataInput();
	char randomChar();
};
