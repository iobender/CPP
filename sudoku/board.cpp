/* 
 * Matthew Bender
 * Jan 21, 2014
 * Class to represent a sudoku board
 */
#include <iostream>
#include <unordered_set>
#include <sstream>
#include <vector>
typedef std::unordered_set<char> square;
typedef std::array<square,9> unit;

class Board {
	private:
		std::unordered_set<char> board[9][9];
	public:

		Board() {
			for(int r= 0; r < 9; r++) {
				for(int c= 0; c < 9; c++) {
					board[r][c]= {'1','2','3','4','5','6','7','8','9'};
				}
			}
		}

		Board(std::string board_str) {
			std::string::size_type num_chars= (board_str.size() < 9*9 ? board_str.size() : 9*9);
			std::string::size_type i;
			for(i= 0; i < num_chars; i++) {
				char c= board_str[i];
				if(c >= '1' && c <= '9') {
					board[i/9][i%9]= {c};
				} else if (c == '.' || c == '0') {
					board[i/9][i%9]= {'1','2','3','4','5','6','7','8','9'};
				} else {
					std::cout << "dec" << std::endl;
					i--;
				}
			}
			for(; i < 9*9; i++) {
				board[i/9][i%9]= {'1','2','3','4','5','6','7','8','9'};
			}
			
		}

		square& at(int index) {
			return at(index/9, index%9);
		}

		square& at(int row, int col) {
			return board[row][col];
		}

		std::array<int,9> rowIndices(int square_num) { 
			return rowIndices(square_num/9, square_num%9); 
		}
		
		std::array<int,9> rowIndices(int row, int col) { 
			std::array<int,9> ret;
			for(int c= 0; c < 9; c++)
				ret[c]= 9*row + c;
			return ret;
		}
		
		std::array<int,9> colIndices(int square_num) { 
			return colIndices(square_num/9, square_num%9); 
		}
		
		std::array<int,9> colIndices(int row, int col) {
			std::array<int,9> ret;
			for(int r= 0; r < 9; r++) {
				ret[r]= 9*r + col;
			}
			return ret;
		}
		
		std::array<int,9> boxIndices(int square_num) { 
			return boxIndices(square_num/9, square_num%9); 
		}

		std::array<int,9> boxIndices(int row, int col) {
			std::array<int,9> ret;
			int count= 0;
			for(int r= row-row%3; r < row-row%3+3; r++) {
				for(int c= col-col%3; c < col-col%3+3; c++) {
					ret[count]= 9*r+c;
					count++;
				}
			}
			return ret;
		}
		
		std::array<int,20> peerIndices(int square_num) { 
			return peerIndices(square_num/9, square_num%9); 
		}
		
		std::array<int,20> peerIndices(int row, int col) {
			std::unordered_set<int> indices;
			for(int r: rowIndices(row,col)) {
				indices.insert(r);
			}
			for(int c: colIndices(row,col)) {
				indices.insert(c);
			}
			for(int b: boxIndices(row,col)) {
				indices.insert(b);
			}
			indices.erase(9*row+col);
			std::array<int,20> ret;
			int count= 0;
			for(auto it= indices.begin(); it != indices.end(); it++) {
				ret[count++]= *it;
			}
			return ret;
		}

		std::string display(bool full= false) {
			std::stringstream ss;
			if(full) {
				for(int r= 0; r < 9; r++) {
					for(int c= 0; c < 9; c++) {
						auto entry= board[r][c];
						int count= 0;
						for(auto it= entry.begin(); it != entry.end(); it++) {
							ss << *it;
							count ++;
						}
						for(; count < 9; count ++) {
							ss << ' ';
						}
						ss << ' ';
					}
					ss << "\n\n";
				}
			} else {
				for(int r= 0; r < 9; r++) {
					if(r != 0 && r%3 == 0)
						ss << "------+-------+------ \n";
					for(int c= 0; c < 9; c++) {
						if(c != 0 && c%3 == 0)
							ss << "| ";
						auto entry= board[r][c];
						if(entry.size() == 1) {
							ss << *entry.begin() << " ";
						} else {
							ss << ". ";
						}
					}
					ss << '\n';
				}
			}
			return ss.str();
		}
};
