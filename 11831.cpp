#include <iostream>
#include <vector>
using namespace std;

int main() {
	int R, C, S, count;
	string line, seq;
	char D;
	vector<string> grid;
	pair<int, int> pos;
	while(true) {
		cin >> R >> C >> S;
		if (!(R||C||S)) break;
		grid.clear();
		for (int r = 0; r < R; r++) {
			cin >> line;
			grid.push_back(line);
		}
		pos = make_pair(-1, -1);
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				if (grid[r][c] == '*' || grid[r][c] == '#' || grid[r][c] == '.') continue;
				pos = make_pair(r, c);
				break;
			}
			if (pos.first != -1) break;
		}
		D = grid[pos.first][pos.second];
		if (D == 'O') D = 'W';
		else if (D == 'L') D = 'E';
		cin >> seq;
		count = 0;
		for (int c = 0; c < seq.length(); c++) {
			if (seq[c] == 'F') {
				if (D == 'N') {
					pos = make_pair(pos.first-1, pos.second);
					if (pos.first < 0 || grid[pos.first][pos.second] == '#') pos = make_pair(pos.first+1, pos.second);
					else if (grid[pos.first][pos.second] == '*') {
						count++;
						grid[pos.first][pos.second] = '.';
					}
				} else if (D == 'S') {
					pos = make_pair(pos.first+1, pos.second);
					if (pos.first >= R || grid[pos.first][pos.second] == '#') pos = make_pair(pos.first-1, pos.second);
					else if (grid[pos.first][pos.second] == '*') {
						count++;
						grid[pos.first][pos.second] = '.';
					}
				} else if (D == 'W') {
					pos = make_pair(pos.first, pos.second-1);
					if (pos.second < 0 || grid[pos.first][pos.second] == '#') pos = make_pair(pos.first, pos.second+1);
					else if (grid[pos.first][pos.second] == '*') {
						count++;
						grid[pos.first][pos.second] = '.';
					}
				} else {
					pos = make_pair(pos.first, pos.second+1);
					if (pos.second >= C || grid[pos.first][pos.second] == '#') pos = make_pair(pos.first, pos.second-1);
					else if (grid[pos.first][pos.second] == '*') {
						count++;
						grid[pos.first][pos.second] = '.';
					}
				}
			} else if (seq[c] == 'D') {
				if (D == 'N') D = 'E';
				else if (D == 'E') D = 'S';
				else if (D == 'S') D = 'W';
				else D = 'N';
			} else {
				if (D == 'N') D = 'W';
				else if (D == 'W') D = 'S';
				else if (D == 'S') D = 'E';
				else D = 'N';
			}
		}
		cout << count << endl;
	}
	return 0;
}
