#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> CC;
vector<int> letCC;
vector<string> grid;
int numCC;

void DFS(int r, int c, char L) {
	if (r < 0 || r >= N) return;
	if (c < 0 || c >= M) return;
	if (grid[r][c] != L) return;
	if (CC[r*M + c] != -1) return;
	CC[r*M + c] = numCC;
	DFS(r+1, c, L);
	DFS(r-1, c, L);
	DFS(r, c+1, L);
	DFS(r, c-1, L);
}

int main() {
	int T, max_ind, max_tot;
	string line;
	cin >> T;
	for (int w = 1; w <= T; w++) {
		cin >> N >> M;
		grid.clear();
		for (int n = 0; n < N; n++) {
			cin >> line;
			grid.push_back(line);
		}
		CC.assign(N*M, -1);
		letCC.assign(26, 0);
		numCC = 0;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				if (CC[r*M + c] == -1) {
					DFS(r, c, grid[r][c]);
					numCC++;
					letCC[grid[r][c] - 'a']++;
				}
			}
		}
		cout << "World #" << w << endl;
		while(true) {
			max_ind = 0;
			max_tot = -1;
			for (int i = 0; i < 26; i++) {
				if (letCC[i] > max_tot) {
					max_tot = letCC[i];
					max_ind = i;
				}
			}
			if (max_tot == 0) break;
			cout << ((char) ('a' + max_ind)) << ": " << max_tot << endl;
			letCC[max_ind] = 0;
		}
	}
	return 0;
}
