#include <iostream>
#include <vector>
using namespace std;

int R, C;
int pointToVal(pair<int, int> P) {
	return C*P.first + P.second;
}

int main() {
	int init, count, steps;
	pair<int, int> pos;
	string row;
	vector<string> grid;
	vector<int> visit;
	bool fell;
	while(true) {
		cin >> R >> C >> init;
		if (!(R||C||init)) break;
		grid.clear();
		for (int r = 0; r < R; r++) {
			cin >> row;
			grid.push_back(row);
		}
		visit.assign(R*C, -1);
		count = 0;
		pos = make_pair(0, init-1);
		visit[pointToVal(pos)] = count;
		count++;
		steps = 0;
		fell = false;
		while(true) {
			steps++;
			if (grid[pos.first][pos.second] == 'N') {
				pos = make_pair(pos.first-1, pos.second);
			} else if (grid[pos.first][pos.second] == 'S') {
				pos = make_pair(pos.first+1, pos.second);
			} else if (grid[pos.first][pos.second] == 'E') {
				pos = make_pair(pos.first, pos.second+1);
			} else {
				pos = make_pair(pos.first, pos.second-1);
			}
			if (pos.first < 0 || pos.first >= R || pos.second < 0 || pos.second >= C) {
				fell = true;
				break;
			}
			if (visit[pointToVal(pos)] == -1) {
				visit[pointToVal(pos)] = count;
				count++;
			} else {
				steps = count - visit[pointToVal(pos)];
				init = visit[pointToVal(pos)];
				break;
			}
		}
		if (fell) {
			cout << steps << " step(s) to exit\n";
		} else {
			cout << init << " step(s) before a loop of " << steps << " step(s)\n";
		}
	}
	return 0;
}
