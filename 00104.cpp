#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
	int N;
	vector<int> seq;
	int parent[20][20][20];
	double adj_matrix[20][20][20];
	while(cin >> N) {
		memset(adj_matrix, 0, sizeof adj_matrix);
		memset(adj_matrix, 0, sizeof parent);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j) continue;
				cin >> adj_matrix[i][j][0];
			}
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				parent[i][j][0] = i;
		for (int s = 1; s < N; s++) {
			for (int k = 0; k < N; k++) {
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						if (adj_matrix[i][j][s] < adj_matrix[i][k][s-1]*adj_matrix[k][j][0]) {
							adj_matrix[i][j][s] = adj_matrix[i][k][s-1]*adj_matrix[k][j][0];
							parent[i][j][s] = k;
						}
					}
				}
			}
		}
		seq.clear();
		bool flag = true;
		for (int s = 1; s < N; s++) {
			if (!flag) break;
			for (int i = 0; i < N; i++) {
				if (adj_matrix[i][i][s] > 1.01) {
					seq.assign(s+1, 0);
					seq[s] = parent[i][i][s];
					for (int j = s-1; j >= 0; j--) {
						seq[j] = parent[i][seq[j+1]][j];
					}
					for (int j = 0; j <= s; j++) cout << (seq[j]+1) << " ";
					cout << (seq[0]+1) << "\n";
					flag = false;
					break;
				}
			}
		}
		if (flag) cout << "no arbitrage sequence exists\n";
	}
	return 0;
}
