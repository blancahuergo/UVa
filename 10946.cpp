#include <iostream>
#include <vector>
using namespace std;

vector<string> grid;
vector<int> CCsizes;
vector<char> CClet;
vector<int> CC;
int numCC, N, M;

void DFS(int r, int c, char L) {
	if (r < 0 || r >= N) return;
	if (c < 0 || c >= M) return;
	if (CC[r*M + c] != -1) return;
	if (grid[r][c] != L) return;
	CC[r*M + c] = numCC;
	CCsizes[numCC]++;
	DFS(r+1, c, L);
	DFS(r-1, c, L);
	DFS(r, c+1, L);
	DFS(r, c-1, L);
}

int main() {
	int max_size, max_ind;
	char max_let;
	string line;
	int cas = 1;
	while(true) {
		cin >> N >> M;
		if (!(N||M)) break;
		grid.clear();
		for (int n = 0; n < N; n++) {
			cin >> line;
			grid.push_back(line);
		}
		numCC = 0;
		CCsizes.clear();
		CCsizes.push_back(0);
		CClet.clear();
		CClet.push_back('a');
		CC.assign(N*M, -1);
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				if (grid[r][c] != '.' && CC[r*M + c] == -1) {
					DFS(r, c, grid[r][c]);
					CClet[numCC] = grid[r][c];
					numCC++;
					CCsizes.push_back(0);
					CClet.push_back('a');
				}
			}
		}
		cout << "Problem " << cas << ":\n";
		while(true) {
			max_size = -1;
			max_let = 'Z';
			for (int i = 0; i < numCC; i++) {
				if (CCsizes[i] > max_size) {
					max_size = CCsizes[i];
					max_ind = i;
					max_let = CClet[i];
				} else if (CCsizes[i] == max_size && CClet[i] < max_let) {
					max_let = CClet[i];
					max_ind = i;
				}
			}
			if (max_size == -1) break;
			cout << max_let << " " << max_size << endl;
			CCsizes[max_ind] = -1;
		}
		cas++;
	}
	return 0;
}
