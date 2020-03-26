#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C;
bool inside (int x, int y) {
	return x >= 0 && y >= 0 && x < R && y < C;
}

int main() {
	int T, x, y;
	vector<vector<int>> grid, dist;
	vector<string> inp;
	vector<int> empt, empt2;
	string line;
	pair<int, int> start_pos, end_pos, cur_pos;
	cin >> T;
	while(T--) {
		cin >> R >> C;
		empt.assign(C, 0);
		grid.assign(R, empt);
		empt2.assign(C, -1);
		dist.assign(R, empt2);
		inp.clear();
		for (int r = 0; r < R; r++) {
			cin >> line;
			inp.push_back(line);
		}
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				if (inp[r][c] == '.') continue;
				else if (inp[r][c] == 'Z') {
					grid[r][c] = 1;
					if (r >= 2) {
						if (c >= 1) grid[r-2][c-1] = 1;
						if (c < C-1) grid[r-2][c+1] = 1;
					}
					if (r < R-2) {
						if (c >= 1) grid[r+2][c-1] = 1;
						if (c < C-1) grid[r+2][c+1] = 1;
					}
					if (r >= 1) {
						if (c >= 2) grid[r-1][c-2] = 1;
						if (c < C-2) grid[r-1][c+2] = 1;
					}
					if (r < R-1) {
						if (c >= 2) grid[r+1][c-2] = 1;
						if (c < C-2) grid[r+1][c+2] = 1;
					}
				}
				else if (inp[r][c] == 'B') end_pos = {r, c};
				else start_pos = {r, c};
			}
		}
		grid[start_pos.first][start_pos.second] = 0;
		grid[end_pos.first][end_pos.second] = 0;
		queue<pair<int, int>> Q;
		Q.push(start_pos);
		dist[start_pos.first][start_pos.second] = 0;
		while(!Q.empty()) {
			cur_pos = Q.front();
			Q.pop();
			x = cur_pos.first;
			y = cur_pos.second;
			if (x == end_pos.first && y == end_pos.second) break;
			for (int i = -1; i <= 1; i++) {
				for (int j = -1; j <= 1; j++) {
					if (inside(x+i, y+j) && grid[x+i][y+j] == 0 && dist[x+i][y+j] == -1) {
						Q.push({x+i, y+j});
						dist[x+i][y+j] = dist[x][y]+1;
					}
				}
			}
		}
		if (dist[end_pos.first][end_pos.second] == -1) cout << "King Peter, you can't go now!\n";
		else cout << "Minimal possible length of a trip is " << dist[end_pos.first][end_pos.second] << "\n";
	}
	return 0;
}
