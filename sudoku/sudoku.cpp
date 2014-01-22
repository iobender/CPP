/* 
 * Matthew Bender
 * Jan 21, 2014
 *
 * Implementation of the Sudoku class found at sudoku.hpp
 */ 
#include "sudoku.hpp"

void Sudoku::propogateConstraint(Board& board, int i, std::unordered_set<int>& soFar) {
	if(board.at(i).size() == 1 && !soFar.count(i)) {
		char c= *board.at(i).begin();
		soFar.insert(i);
		for(int ind: board.peerIndices(i)) {
			board.at(ind).erase(c);
			propogateConstraint(board, ind, soFar);
		}
	}
}

void Sudoku::propogateConstraints(Board& board) {
	std::unordered_set<int> soFar; //squares propgated so far
	for(int i= 0; i < 9*9; i++) {
		propogateConstraint(board, i, soFar);
	}
}

void Sudoku::solve(Board& board) {
	propogateConstraints(board);
}
