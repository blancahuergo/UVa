#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M, numCC;
vector<string> grid;
vector<int> CC;

void DFS(int r, int c) {
	if (r < 0 || r >= N) return;
	if (c < 0 || c >= M) return;
	if (grid[r][c] != '@') return;
	if (CC[M*r + c] != -1) return;
	CC[r*M + c] = numCC;
	DFS(r+1, c);
	DFS(r, c);
	DFS(r-1, c);
	DFS(r+1, c+1);
	DFS(r, c+1);
	DFS(r-1, c+1);
	DFS(r+1, c-1);
	DFS(r, c-1);
	DFS(r-1, c-1);
}

int main() {
	string line;
	while(true) {
		cin >> N >> M;
		if (!(N || M)) break;
		grid.clear();
		for (int n = 0; n < N; n++) {
			cin >> line;
			grid.push_back(line);
		}
		CC.assign(N*M, -1);
		numCC = 0;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				if (CC[r*M + c] == -1 && grid[r][c] == '@') {
					DFS(r, c);
					numCC++;
				}
			}
		}
		int CCsizes[numCC];
		memset(CCsizes, 0, sizeof CCsizes);
		for (int n = 0; n < CC.size(); n++) {
			CCsizes[CC[n]]++;
		}
		cout << numCC << endl;
	}
	return 0;
}
