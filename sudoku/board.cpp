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
		unit row(int square_num) { return row(square_num/9, square_num%9); }
		unit row(int row, int col) { 
			unit ret;
			for(int c= 0; c < 9; c++) {
				ret[c]= board[row][c];
			}
			return ret;
		}
		unit col(int square_num) { return col(square_num/9, square_num%9); }
		unit col(int row, int col) {
			unit ret;
			for(int r= 0; r < 9; r++) {
				ret[r]= board[r][col];
			}

			return ret;
		}
		unit box(int square_num) { return box(square_num/9, square_num%9); }
		unit box(int row, int col) {
			unit ret;
			int count= 0;
			for(int r= row-row%3; r < row-row%3+3; r++) {
				for(int c= col-col%3; c < col-col%3+3; c++) {
					ret[count]= board[r][c];
					count++;
				}
			}
			return ret;
		}
		std::string display() {
			std::stringstream ss;
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
			return ss.str();
		}
};
