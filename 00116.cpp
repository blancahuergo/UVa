#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> grid, DP;
vector<int> path;
vector<vector<int>> pre;
int R, C, len, first;

void fillIn() {
	pair<int, int> cur;
	DP.assign(R, vector<int>(C, 2e9));
	queue<pair<int, int>> Q;
	for (int i = 0; i < R; i++) {
		DP[i][C-1] = grid[i][C-1];
		Q.push({i*C + C-1, DP[i][C-1]});
	}
	int r, c, dist;
	len = 2e9;
	while(!Q.empty()) {
		cur = Q.front();
		Q.pop();
		dist = cur.second;
		r = cur.first/C;
		c = cur.first%C;
		if (DP[r][c] < dist) continue;
		if (c == 0) {
			if (dist < len) {
				len = dist;
				first = r;
			} else if (dist == len && r < first) first = r;
			continue;
		}
		if (r == R-1) {
			if (DP[0][c-1] > dist + grid[0][c-1]) {
				DP[0][c-1] = dist + grid[0][c-1];
				Q.push({c-1, DP[0][c-1]});
				pre[0][c-1] = r;
			} else if (DP[0][c-1] == dist + grid[0][c-1] && pre[0][c-1] > r)
				pre[0][c-1] = r;
		}
		if (r > 0) {
			if (DP[r-1][c-1] > dist + grid[r-1][c-1]) {
				DP[r-1][c-1] = dist + grid[r-1][c-1];
				Q.push({(r-1)*C + c-1, DP[r-1][c-1]});
				pre[r-1][c-1] = r;
			} else if (DP[r-1][c-1] == dist + grid[r-1][c-1] && pre[r-1][c-1] > r)
				pre[r-1][c-1] = r;
		}
		if (DP[r][c-1] > dist + grid[r][c-1]) {
			DP[r][c-1] = dist + grid[r][c-1];
			Q.push({r*C + c-1, DP[r][c-1]});
			pre[r][c-1] = r;
		} else if (DP[r][c-1] == dist + grid[r][c-1] && pre[r][c-1] > r)
			pre[r][c-1] = r;
		if (r < R-1) {
			if (DP[r+1][c-1] > dist + grid[r+1][c-1]) {
				DP[r+1][c-1] = dist + grid[r+1][c-1];
				Q.push({(r+1)*C + c-1, DP[r+1][c-1]});
				pre[r+1][c-1] = r;
			} else if (DP[r+1][c-1] == dist + grid[r+1][c-1] && pre[r+1][c-1] > r)
				pre[r+1][c-1] = r;
		}
		if (r == 0) {
			if (DP[R-1][c-1] > dist + grid[R-1][c-1]) {
				DP[R-1][c-1] = dist + grid[R-1][c-1];
				Q.push({(R-1)*C + c-1, DP[R-1][c-1]});
				pre[R-1][c-1] = r;
			} else if (DP[R-1][c-1] == dist + grid[R-1][c-1] && pre[R-1][c-1] > r)
				pre[R-1][c-1] = r;
		}
	}
}

void buildPath() {
	path.assign(C, 0);
	int c = 0, r = first;
	while(c < C-1) {
		path[c] = r;
		r = pre[r][c];
		c++;
	}
	path[C-1] = r;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while(cin >> R >> C) {
		grid.assign(R, vector<int>(C,0));
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++) cin >> grid[i][j];
		pre.assign(R, vector<int>(C, 0));
		fillIn();
		buildPath();
		cout << path[0]+1;
		for (int i = 1; i < C; i++) cout << ' ' << path[i]+1;
		cout << "\n" << len << "\n";
	}
	return 0;
}
