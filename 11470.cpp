#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> grid;

void traverse(int r, int c, int L) {
	int total = 0;
	for (int i = c; i < c+L; i++) total += (grid[r][i] + grid[r+L-1][i]);
	for (int i = r; i < r+L; i++) total += (grid[i][c] + grid[i][c+L-1]);
	total -= (grid[r][c] + grid[r+L-1][c] + grid[r][c+L-1] + grid[r+L-1][c+L-1]);
	if (L == 1) total = grid[r][c];
	cout << " " << total;
	if (L <= 2) return;
	traverse(r+1, c+1, L-2);
}

int main() {
	int cas = 1;
	vector<int> empt;
	while(true) {
		cin >> N;
		if (!N) break;
		empt.assign(N, 0);
		grid.assign(N, empt);
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				cin >> grid[r][c];
			}
		}
		cout << "Case " << cas << ":";
		traverse(0, 0, N);
		cout << "\n";
		cas++;
	}
	return 0;
}
