#include <iostream>
#include <vector>
using namespace std;

int R, C, X, Y;
vector<string> grid;
vector<int> CC;
vector<int> CCsizes;
vector<int> CCF, CCS;
int numCC;

void DFS(int r, int c, char L) {
	if (r < 0 || r >= R) return;
	if (c < 0 || c >= C) return;
	if (grid[r][c] != L) return;
	if (CC[r*C + c] != -1) return;
	CC[r*C + c] = numCC;
	CCsizes[numCC]++;
	if (c == C-1) {
		DFS(r, 0, L);
		DFS(r-1, c, L);
		DFS(r+1, c, L);
		DFS(r, C-2, L);
	} else if (c == 0) {
		DFS(r, C-1, L);
		DFS(r-1, 0, L);
		DFS(r+1, 0, L);
		DFS(r, 1, L);
	} else {
		DFS(r+1, c, L);
		DFS(r, c+1, L);
		DFS(r-1, c, L);
		DFS(r, c-1, L);
	}
}

int main() {
	string line;
	char F, S;
	int cur_size, max_s, max_sec;
	while(cin >> R >> C) {
		grid.clear();
		for (int r = 0; r < R; r++) {
			cin >> line;
			grid.push_back(line);
		}
		F = grid[0][0];
		S = '.';
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				if (grid[r][c] == 'F') continue;
				else {
					S = grid[r][c];
					break;
				}
			}
		}
		numCC = 0;
		CC.assign(R*C, -1);
		CCsizes.clear();
		CCsizes.push_back(0);
		CCF.clear();
		CCS.clear();
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				if (CC[r*C + c] == -1) {
					DFS(r, c, grid[r][c]);
					CCsizes.push_back(0);
					if (grid[r][c] == F) {
						CCF.push_back(numCC);
					}
					else {
						CCS.push_back(numCC);
					}
					numCC++;
				}
			}
		}
		cin >> X >> Y;
		cur_size = CCsizes[CC[X*C + Y]];
		max_s = 0;
		max_sec = 0;
		if (grid[X][Y] == F) {
			if (CCF.size() > 1) {
				for (int i = 0; i < CCF.size(); i++) {
					if (CCsizes[CCF[i]] > max_s) {
						max_sec = max_s;
						max_s = CCsizes[CCF[i]];
					} else if (CCsizes[CCF[i]] > max_sec) max_sec = CCsizes[CCF[i]];
				}
			}
		} else {
			if (CCS.size() > 1) {
				for (int i = 0; i < CCS.size(); i++) {
					if (CCsizes[CCS[i]] > max_s) {
						max_sec = max_s;
						max_s = CCsizes[CCS[i]];
					} else if (CCsizes[CCS[i]] > max_sec) max_sec = CCsizes[CCS[i]];
				}
			}
		}
		if (max_s == cur_size) cout << max_sec << endl;
		else cout << max_s << endl;
	}
	return 0;
}
