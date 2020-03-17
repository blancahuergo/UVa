#include <iostream>
#include <vector>
using namespace std;

vector<string> grid;
vector<int> CC, CCsizes;
int N, numCC;

void DFS(int r, int c) {
	if (r < 0 || r >= N) return;
	if (c < 0 || c >= N) return;
	if (grid[r][c] != '1') return;
	if (CC[N*r + c] != -1) return;
	CC[N*r + c] = numCC;
	CCsizes[numCC]++;
	DFS(r+1, c+1);
	DFS(r+1, c);
	DFS(r+1, c-1);
	DFS(r, c+1);
	DFS(r, c-1);
	DFS(r-1, c+1);
	DFS(r-1, c);
	DFS(r-1, c-1);
}

int main() {
	int T, max_size;
	string line;
	cin >> T;
	while(T--) {
		cin >> line;
		grid.clear();
		grid.push_back(line);
		N = line.length();
		for (int n = 1; n < N; n++) {
			cin >> line;
			grid.push_back(line);
		}
		numCC = 0;
		CC.assign(N*N, -1);
		CCsizes.clear();
		CCsizes.push_back(0);
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (CC[N*r + c] == -1 && grid[r][c] == '1') {
					DFS(r, c);
					numCC++;
					CCsizes.push_back(0);
				}
			}
		}
		max_size = 0;
		for (int i = 0; i < CCsizes.size(); i++) {
			max_size = max(max_size, CCsizes[i]);
		}
		cout << max_size << endl;
		if (T) cout << "\n";
	}
	return 0;
}
