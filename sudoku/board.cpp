/* 
 * Matthew Bender
 * Jan 21, 2014
 * Class to represent a sudoku board
 */
#include <iostream>
#include <unordered_set>
#include <sstream>

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
			std::cout << num_chars << std::endl;
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
		std::string display() {
			std::stringstream ss;
			for(int r= 0; r < 9; r++) {
				for(int c= 0; c < 9; c++) {
					auto entry= board[r][c];
					for(auto it= entry.begin(); it != entry.end(); it++) {
						ss << *it;
					}
					ss << ' ';
				}
				ss << std::endl;
			}
			return ss.str();
		}
};
