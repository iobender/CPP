/* 
 * Matthew Bender
 * Jan 21, 2014
 * Class to represent a sudoku board
 */
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
