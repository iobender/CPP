/*
 * Matthew Bender
 * Jan 21, 2014
 *
 * Header files for sudoko solver
 */
#include "board.cpp"

class Sudoku {
	private:
	public:
		static void propogateConstraints(Board&);
		static void solve(Board&);
};
