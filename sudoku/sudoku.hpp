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
		static char digits[];
		static void propogateConstraint(Board&, int, std::unordered_set<int>&);
		static void findUnique(Board&, int, std::unordered_set<int>&);
		static void removeUnique(Board&, std::array<int,9>, std::unordered_set<int>&);
		static void propogateConstraints(Board&);
		static void solve(Board&);
};
