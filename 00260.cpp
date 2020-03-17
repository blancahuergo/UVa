#include <iostream>
#include <vector>
using namespace std;

vector<string> grid;
int winner;
int N;
vector<bool> visited;

void DFS(int r, int c) {
	if (r < 0 || r >= N) return;
	if (c < 0 || c >= N) return;
	if (visited[r*N + c]) return;
	if (grid[r][c] == 'w') return;
	visited[r*N+c] = true;
	if (r == N-1) winner = 1;
	DFS(r - 1, c - 1);
	DFS(r - 1, c);
	DFS(r, c - 1);
	DFS(r, c + 1);
	DFS(r + 1, c);
	DFS(r + 1, c + 1);
}

int main() {
	string line;
	int cas = 1;
	while(true) {
		cin >> N;
		if (!N) break;
		grid.clear();
		for (int n = 0; n < N; n++) {
			cin >> line;
			grid.push_back(line);
		}
		winner = 0;
		visited.assign(N*N, false);
		for (int c = 0; c < N; c++) {
			if (grid[0][c] == 'b' && (!visited[c])) {
				DFS(0, c);
				if (winner == 1) break;
			}
		}
		if (winner == 1) cout << cas << " B\n";
		else cout << cas << " W\n";
		cas++;
	}
	return 0;
}
