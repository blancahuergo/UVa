#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> grid;
vector<vector<int>> DP;

int maxPath(int r, int c) {
	if (DP[r][c] != -1) return DP[r][c];
	if (r >= DP.size() || r < 0) return -300;
	if (c >= DP[0].size() || c < 0) return -300;
	int ret = 1;
	if (r >= 1 && grid[r-1][c] < grid[r][c])
		ret = max(ret, 1+maxPath(r-1, c));
	if (r+1 < DP.size() && grid[r+1][c] < grid[r][c])
		ret = max(ret, 1+maxPath(r+1, c));
	if (c >= 1 && grid[r][c-1] < grid[r][c])
		ret = max(ret, 1+maxPath(r, c-1));
	if (c+1 < DP[0].size() && grid[r][c+1] < grid[r][c])
		ret = max(ret, 1+maxPath(r, c+1));
	DP[r][c] = ret;
	return ret;
}

int maxLen() {
	int R = grid.size();
	int C = grid[0].size();
	int max_val = -1, cur_val;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cur_val = maxPath(r, c);
			max_val = max(max_val, cur_val);
		}
	}
	return max_val;
}


int main() {
	int T, R, C;
	string nam;
	vector<int> empty;
	cin >> T;
	while(T--) {
		cin >> nam >> R >> C;
		empty.assign(C, -1);
		grid.assign(R, empty);
		DP.assign(R, empty);
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				cin >> grid[r][c];
			}
		}
		cout << nam << ": " << maxLen() << endl;
	}
	return 0;
}
