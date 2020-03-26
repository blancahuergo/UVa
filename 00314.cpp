#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int R, C;
vector<vector<int>> grid;
vector<vector<vector<int>>> dist;

bool valid(int x, int y) {
	return ((x > 0) && (y > 0) && (x < R) && (y < C));
}

bool safe(int x, int y) {
	if (grid[x][y] || grid[x-1][y] || grid[x][y-1] || grid[x-1][y-1]) return false;
	else return true;
}

int main() {
	int xS, yS, xE, yE, x, y, D;
	string dir;
	vector<int> empt, empt2;
	vector<vector<int>> empt3;
	empt2.assign(4, -1);
	while (true) {
		cin >> R >> C;
		if (!(R || C)) break;
		empt.assign(C, 0);
		grid.assign(R, empt);
		empt3.assign(C+1, empt2);
		dist.assign(R+1, empt3);
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				cin >> grid[r][c];
			}
		}
		cin >> xS >> yS >> xE >> yE >> dir;
		if (!(valid(xS, yS) && valid(xE, yE))) {
			cout << "-1\n";
			continue;
		}
		if (!(safe(xS, yS) && safe(xE, yE))) {
			cout << "-1\n";
			continue;
		}
		queue<vector<int>> Q;
		if (dir[0] == 'n') {
			dist[xS][yS][0] = 0;
			Q.push({xS, yS, 0});
		} else if (dir[0] == 's') {
			dist[xS][yS][1] = 0;
			Q.push({xS, yS, 1});
		} else if (dir[0] == 'w') {
			dist[xS][yS][2] = 0;
			Q.push({xS, yS, 2});
		} else {
			dist[xS][yS][3] = 0;
			Q.push({xS, yS, 3});
		}
		vector<int> cur;
		int ans = 2000000000;
		while (!Q.empty()) {
			cur = Q.front();
			Q.pop();
			y = cur[1];
			x = cur[0];
			D = cur[2];
			if (x == xE && y == yE) {
				ans = dist[x][y][D];
				break;
			}
			if (D == 0) {
				for (int dif = -1; dif >= -3; dif--) {
					if (valid(x+dif, y) && safe(x+dif, y)) {
						if (dist[x+dif][y][D] == -1) {
							Q.push({x+dif, y, D});
							dist[x+dif][y][D] = dist[x][y][D]+1;
						}
					} else break;
				}
			} else if (D == 1) {
				for (int dif = 1; dif <= 3; dif++) {
					if (valid(x+dif, y) && safe(x+dif, y)) {
						if (dist[x+dif][y][D] == -1) {
							Q.push({x+dif, y, D});
							dist[x+dif][y][D] = dist[x][y][D]+1;
						}
					} else break;
				}
			} else if (D == 2) {
				for (int dif = -1; dif >= -3; dif--) {
					if (valid(x, y+dif) && safe(x, y+dif)) {
						if (dist[x][y+dif][D] == -1) {
							Q.push({x, y+dif, D});
							dist[x][y+dif][D] = dist[x][y][D]+1;
						}
					} else break;
				}
			} else {
				for (int dif = 1; dif <= 3; dif++) {
					if (valid(x, y+dif) && safe(x, y+dif)) {
						if (dist[x][y+dif][D] == -1) {
							Q.push({x, y+dif, D});
							dist[x][y+dif][D] = dist[x][y][D]+1;
						}
					} else break;
				}
			}
			if (D == 0) {
				if (dist[x][y][2] == -1) {
					Q.push({x, y, 2});
					dist[x][y][2] = dist[x][y][0]+1;
				}
				if (dist[x][y][3] == -1) {
					Q.push({x, y, 3});
					dist[x][y][3] = dist[x][y][0]+1;
				}
			} else if (D == 1) {
				if (dist[x][y][2] == -1) {
					Q.push({x, y, 2});
					dist[x][y][2] = dist[x][y][1]+1;
				}
				if (dist[x][y][3] == -1) {
					Q.push({x, y, 3});
					dist[x][y][3] = dist[x][y][1]+1;
				}
			} else if (D == 2) {
				if (dist[x][y][0] == -1) {
					Q.push({x, y, 0});
					dist[x][y][0] = dist[x][y][2]+1;
				}
				if (dist[x][y][1] == -1) {
					Q.push({x, y, 1});
					dist[x][y][1] = dist[x][y][2]+1;
				}
			} else {
				if (dist[x][y][0] == -1) {
					Q.push({x, y, 0});
					dist[x][y][0] = dist[x][y][3]+1;
				}
				if (dist[x][y][1] == -1) {
					Q.push({x, y, 1});
					dist[x][y][1] = dist[x][y][3]+1;
				}
			}
		}
		if (ans == 2000000000)
			cout << "-1\n";
		else
			cout << ans << "\n";
	}
	return 0;
}
