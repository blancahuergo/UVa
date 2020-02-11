#include <iostream>
using namespace std;

int main() {
	string s;
	int cas = 1;
	int row, col;
	while(getline(cin, s)) {
		int matrix[3][3];
		for (int i = 0; i < 3; i++) {
			matrix[i][0] = 0;
			matrix[i][1] = 0;
			matrix[i][2] = 0;
		}
		for (int c = 0; c < s.length(); c++) {
			switch(s[c]) {
			case 'a':
				row = 0;
				col = 0;
				break;
			case 'b':
				row = 0;
				col = 1;
				break;
			case 'c':
				row = 0;
				col = 2;
				break;
			case 'd':
				row = 1;
				col = 0;
				break;
			case 'e':
				row = 1;
				col = 1;
				break;
			case 'f':
				row = 1;
				col = 2;
				break;
			case 'g':
				row = 2;
				col = 0;
				break;
			case 'h':
				row = 2;
				col = 1;
				break;
			case 'i':
				row = 2;
				col = 2;
				break;
			default:
				break;
			}
			matrix[row][col] = (matrix[row][col]+1)%10;
			if (row-1 >= 0) {
				matrix[row-1][col] = (matrix[row-1][col]+1)%10;
			}
			if (col-1 >= 0) {
				matrix[row][col-1] = (matrix[row][col-1]+1)%10;
			}
			if (row+1 <= 2) {
				matrix[row+1][col] = (matrix[row+1][col]+1)%10;
			}
			if (col+1 <= 2) {
				matrix[row][col+1] = (matrix[row][col+1]+1)%10;
			}
		}
		cout << "Case #" << cas << ":" << endl;
		for (int r = 0; r < 3; r++) {
			cout << matrix[r][0] << " " << matrix[r][1] << " " << matrix[r][2] << endl;
		}
		cas++;
	}
	return 0;
}
