/* 
 * Matthew Bender
 * Jan 21, 2014
 *
 * Implementation of the Sudoku class found at sudoku.hpp
 */ 
#include "sudoku.hpp"

char Sudoku::digits[]= {'1','2','3','4','5','6','7','8','9'};

void Sudoku::propogateConstraint(Board& board, int i, std::unordered_set<int>& soFar) {
	if(board.at(i).size() == 1 && !soFar.count(i)) {
		char c= *board.at(i).begin();
		soFar.insert(i);
		for(int ind: board.peerIndices(i)) {
			board.at(ind).erase(c);
			propogateConstraint(board, ind, soFar);
			findUnique(board, ind, soFar);
		}
	}
}

void Sudoku::findUnique(Board& board, int i, std::unordered_set<int>& soFar) {
	for(int r= 0; r < 9; r++) {
		removeUnique(board, board.rowIndices(r, 0), soFar);
	}
	for(int c= 0; c < 9; c++) {
		removeUnique(board, board.colIndices(0, c), soFar);
	}
	for(int r= 0; r < 9; r += 3) {
		for(int c= 0; c < 9; c += 3) {
			removeUnique(board, board.boxIndices(r,c), soFar);
		}
	}
}

void Sudoku::removeUnique(Board& board, std::array<int,9> indices, std::unordered_set<int>& soFar) {
	for(char dig: digits) {
		std::unordered_set<int> digOccs;
		for(int i: indices) {
			if(board.at(i).count(dig))
				digOccs.insert(i);
		}
		if(digOccs.size() == 1) {
			int index= *digOccs.begin();
			board.at(index).clear();
			board.at(index).insert(dig);
			propogateConstraint(board, index, soFar);
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
