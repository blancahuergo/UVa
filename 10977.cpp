#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int R, C, M, x, y, L, ds;
	vector<vector<int>> grid, dist;
	vector<int> empt, empt2;
	while(true) {
		cin >> R >> C;
		if (!(R||C)) break;
		empt.assign(C, 0);
		empt2.assign(C, -1);
		grid.assign(R, empt);
		dist.assign(R, empt2);
		cin >> M;
		for (int m = 0; m < M; m++) {
			cin >> x >> y;
			grid[x-1][y-1] = 1;
		}
		cin >> M;
		for (int m = 0; m < M; m++) {
			cin >> x >> y >> L;
			x--;
			y--;
			grid[x][y] = 1;
			for (int r = max(0, x - L); r <= min(R-1, x + L); r++) {
				for (int c = max(0, y - L); c <= min(C-1, y + L); c++) {
					ds = (y-c)*(y-c)+(x-r)*(x-r);
					if (ds <= L*L) grid[r][c] = 1;
				}
			}
		}
		queue<pair<int, int>> Q;
		pair<int, int> S;
		Q.push({0, 0});
		dist[0][0] = 0;
		while(!Q.empty()) {
			S = Q.front();
			Q.pop();
			if (S.first == R-1 && S.second == C-1) break;
			if (S.first > 0) {
				if (grid[S.first-1][S.second] == 0 && dist[S.first-1][S.second] == -1) {
					dist[S.first-1][S.second] = dist[S.first][S.second]+1;
					Q.push({S.first-1, S.second});
				}
			}
			if (S.first < R-1) {
				if (grid[S.first+1][S.second] == 0 && dist[S.first+1][S.second] == -1) {
					dist[S.first+1][S.second] = dist[S.first][S.second]+1;
					Q.push({S.first+1, S.second});
				}
			}
			if (S.second > 0) {
				if (grid[S.first][S.second-1] == 0 && dist[S.first][S.second-1] == -1) {
					dist[S.first][S.second-1] = dist[S.first][S.second]+1;
					Q.push({S.first, S.second-1});
				}
			}
			if (S.second < C-1) {
				if (grid[S.first][S.second+1] == 0 && dist[S.first][S.second+1] == -1) {
					dist[S.first][S.second+1] = dist[S.first][S.second]+1;
					Q.push({S.first, S.second+1});
				}
			}
		}
		if (dist[R-1][C-1] == -1) cout << "Impossible.\n";
		else cout << dist[R-1][C-1] << "\n";
	}
	return 0;
}
