#include <iostream>
#include <vector>
using namespace std;

vector<string> grid;
vector<int> CC;
int numCC;
int N;

void DFS(int r, int c) {
	if (r < 0 || r >= N) return;
	if (c < 0 || c >= N) return;
	if (grid[r][c] == '0') return;
	if (CC[r*N + c] != -1) return;
	CC[r*N + c] = numCC;
	DFS(r+1, c+1);
	DFS(r+1, c);
	DFS(r+1, c-1);
	DFS(r, c+1);
	DFS(r, c);
	DFS(r, c-1);
	DFS(r-1, c+1);
	DFS(r-1, c);
	DFS(r-1, c-1);
}

int main() {
	string line;
	int cas = 1;
	while(cin >> N) {
		grid.clear();
		for (int n = 0; n < N; n++) {
			cin >> line;
			grid.push_back(line);
		}
		numCC = 0;
		CC.assign(N*N, -1);
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (CC[r*N + c] == -1 && grid[r][c] == '1') {
					DFS(r, c);
					numCC++;
				}
			}
		}
		cout << "Image number " << cas << " contains " << numCC << " war eagles.\n";
		cas++;
	}
	return 0;
}
