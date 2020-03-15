#include <iostream>
#include <cstring>
using namespace std;

int X, Y;

pair<int, int> move_E(pair<int, int> pos) {
	return make_pair(pos.first+1, pos.second);
}

pair<int, int> move_W(pair<int, int> pos) {
	return make_pair(pos.first-1, pos.second);
}

pair<int, int> move_S(pair<int, int> pos) {
	return make_pair(pos.first, pos.second-1);
}

pair<int, int> move_N(pair<int, int> pos) {
	return make_pair(pos.first, pos.second+1);
}

char change_dir(char D, char C) {
	if (C == 'R') {
		if (D == 'N') return 'E';
		else if (D == 'E') return 'S';
		else if (D == 'S') return 'W';
		else return 'N';
	} else {
		if (D == 'N') return 'W';
		else if (D == 'W') return 'S';
		else if (D == 'S') return 'E';
		else return 'N';
	}
}

bool fallen(pair<int, int> pos) {
	if (pos.first < 0 || pos.first > X) return true;
	if (pos.second < 0 || pos.second > Y) return true;
	return false;
}

int main() {
	int x, y;
	string dir, seq;
	pair<int, int> pos, last = make_pair(0, 0);
	char D;
	bool F;
	cin >> X >> Y;
	int grid[X+1][Y+1];
	memset(grid, 0, sizeof grid);
	while(cin >> x >> y) {
		cin >> dir >> seq;
		D = dir[0];
		pos = make_pair(x, y);
		last = pos;
		F = false;
		for (int c = 0; c < seq.length(); c++) {
			if (seq[c] == 'F') {
				if (D == 'N') pos = move_N(pos);
				else if (D == 'S') pos = move_S(pos);
				else if (D == 'E') pos = move_E(pos);
				else pos = move_W(pos);
				if (fallen(pos)) {
					pos = last;
					if (!grid[pos.first][pos.second]) {
						F = true;
						grid[pos.first][pos.second] = 1;
						break;
					}
				}
				last = pos;
			}
			else D = change_dir(D, seq[c]);
		}
		if (!F)
			cout << pos.first << " " << pos.second << " " << D << endl;
		else
			cout << pos.first << " " << pos.second << " " << D << " LOST\n";
	}
	return 0;
}
