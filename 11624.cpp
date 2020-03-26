#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C;
vector<string> grid;
vector<vector<int>> distJ, distF;

void BFS_Fire(vector<pair<int, int>> Fire) {
	int x, y;
	vector<int> empt;
	empt.assign(C, -1);
	distF.assign(R, empt);
	queue<pair<int, int>> Q;
	for (int i = 0; i < Fire.size(); i++) {
		distF[Fire[i].first][Fire[i].second] = 0;
		Q.push(Fire[i]);
	}
	pair<int, int> P;
	while(!Q.empty()) {
		P = Q.front();
		Q.pop();
		x = P.first;
		y = P.second;
		if (x > 0 && distF[x-1][y] == -1 && grid[x-1][y] != '#') {
			Q.push({x-1, y});
			distF[x-1][y] = distF[x][y]+1;
		}
		if (y > 0 && distF[x][y-1] == -1 && grid[x][y-1] != '#') {
			Q.push({x, y-1});
			distF[x][y-1] = distF[x][y]+1;
		}
		if (x < R-1 && distF[x+1][y] == -1 && grid[x+1][y] != '#') {
			Q.push({x+1, y});
			distF[x+1][y] = distF[x][y]+1;
		}
		if (y < C-1 && distF[x][y+1] == -1 && grid[x][y+1] != '#') {
			Q.push({x, y+1});
			distF[x][y+1] = distF[x][y]+1;
		}
	}
}

int BFS_Joe(pair<int, int> P) {
	int x, y;
	vector<int> empt;
	empt.assign(C, -1);
	distJ.assign(R, empt);
	queue<pair<int, int>> Q;
	Q.push(P);
	distJ[P.first][P.second] = 0;
	while(!Q.empty()) {
		P = Q.front();
		Q.pop();
		x = P.first;
		y = P.second;
		if (x > 0 && distJ[x-1][y] == -1 && grid[x-1][y] != '#' && (distF[x-1][y] > distJ[x][y]+1 || distF[x-1][y] == -1)) {
			Q.push({x-1, y});
			distJ[x-1][y] = distJ[x][y]+1;
		}
		if (y > 0 && distJ[x][y-1] == -1 && grid[x][y-1] != '#' && (distF[x][y-1] > distJ[x][y]+1 || distF[x][y-1] == -1)) {
			Q.push({x, y-1});
			distJ[x][y-1] = distJ[x][y]+1;
		}
		if (x < R-1 && distJ[x+1][y] == -1 && grid[x+1][y] != '#' && (distF[x+1][y] > distJ[x][y]+1 || distF[x+1][y] == -1)) {
			Q.push({x+1, y});
			distJ[x+1][y] = distJ[x][y]+1;
		}
		if (y < C-1 && distJ[x][y+1] == -1 && grid[x][y+1] != '#' && (distF[x][y+1] > distJ[x][y]+1 || distF[x][y+1] == -1)) {
			Q.push({x, y+1});
			distJ[x][y+1] = distJ[x][y]+1;
		}
	}
	int ans = 2000000000;
	for (int r = 0; r < R; r++) {
		if (distJ[r][0] != -1) ans = min(ans, distJ[r][0]);
		if (distJ[r][C-1] != -1) ans = min(ans, distJ[r][C-1]);
	}
	for (int c = 0; c < C; c++) {
		if (distJ[0][c] != -1) ans = min(ans, distJ[0][c]);
		if (distJ[R-1][c] != -1) ans = min(ans, distJ[R-1][c]);
	}
	if (ans == 2000000000) return -1;
	return ans+1;
}

int main() {
	int T, ans;
	cin >> T;
	string line;
	pair<int, int> joe;
	vector<pair<int, int>> fire;
	while(T--) {
		cin >> R >> C;
		grid.clear();
		fire.clear();
		for (int r = 0; r < R; r++) {
			cin >> line;
			grid.push_back(line);
			for (int c = 0; c < C; c++) {
				if (line[c] == 'J') joe = {r, c};
				else if (line[c] == 'F') fire.push_back({r, c});
			}
		}
		if (fire.size() == 0) {
			vector<int> empt;
			empt.assign(C, -1);
			distF.assign(R, empt);
		} else {
			BFS_Fire(fire);
		}
		ans = BFS_Joe(joe);
		if (ans == -1) cout << "IMPOSSIBLE\n";
		else cout << ans << "\n";
	}
	return 0;
}
