#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main() {
	int L, R, C;
	vector<int> S, D;
	string line;
	vector<string> empt;
	vector<vector<string>> grid;
	vector<vector<vector<int>>> dist;
	vector<int> emptLine;
	vector<vector<int>> emptLev;
	while(true) {
		cin >> L >> R >> C;
		if (!(L||R||C)) break;
		emptLine.assign(C, -1);
		emptLev.assign(R, emptLine);
		dist.assign(L, emptLev);
		grid.assign(L, empt);
		for (int l = 0; l < L; l++) {
			for (int r = 0; r < R; r++) {
				cin >> line;
				grid[l].push_back(line);
				for (int c = 0; c < C; c++) {
					if (line[c] == 'S') {
						S = {l, r, c};
					} else if (line[c] == 'E') {
						D = {l, r, c};
					}
				}
			}
		}
		queue<vector<int>> Q;
		Q.push(S);
		dist[S[0]][S[1]][S[2]] = 0;
		while(!Q.empty()) {
			S = Q.front();
			if (S[0] == D[0] && S[1] == D[1] && S[2] == D[2]) break;
			Q.pop();
			if (S[0] > 0) {
				if (grid[S[0]-1][S[1]][S[2]] != '#' && dist[S[0]-1][S[1]][S[2]] == -1) {
					dist[S[0]-1][S[1]][S[2]] = dist[S[0]][S[1]][S[2]] + 1;
					Q.push({S[0]-1, S[1], S[2]});
				}
			}
			if (S[0] < L-1) {
				if (grid[S[0]+1][S[1]][S[2]] != '#' && dist[S[0]+1][S[1]][S[2]] == -1) {
					dist[S[0]+1][S[1]][S[2]] = dist[S[0]][S[1]][S[2]] + 1;
					Q.push({S[0]+1, S[1], S[2]});
				}
			}
			if (S[1] > 0) {
				if (grid[S[0]][S[1]-1][S[2]] != '#' && dist[S[0]][S[1]-1][S[2]] == -1) {
					dist[S[0]][S[1]-1][S[2]] = dist[S[0]][S[1]][S[2]] + 1;
					Q.push({S[0], S[1]-1, S[2]});
				}
			}
			if (S[1] < R-1) {
				if (grid[S[0]][S[1]+1][S[2]] != '#' && dist[S[0]][S[1]+1][S[2]] == -1) {
					dist[S[0]][S[1]+1][S[2]] = dist[S[0]][S[1]][S[2]] + 1;
					Q.push({S[0], S[1]+1, S[2]});
				}
			}
			if (S[2] > 0) {
				if (grid[S[0]][S[1]][S[2]-1] != '#' && dist[S[0]][S[1]][S[2]-1] == -1) {
					dist[S[0]][S[1]][S[2]-1] = dist[S[0]][S[1]][S[2]] + 1;
					Q.push({S[0], S[1], S[2]-1});
				}
			}
			if (S[2] < C-1) {
				if (grid[S[0]][S[1]][S[2]+1] != '#' && dist[S[0]][S[1]][S[2]+1] == -1) {
					dist[S[0]][S[1]][S[2]+1] = dist[S[0]][S[1]][S[2]] + 1;
					Q.push({S[0], S[1], S[2]+1});
				}
			}
		}
		if (dist[D[0]][D[1]][D[2]] == -1) cout << "Trapped!\n";
		else cout << "Escaped in " << dist[D[0]][D[1]][D[2]] << " minute(s).\n";
	}
	return 0;
}
