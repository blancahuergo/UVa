#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, plusINF = 1000000000;
	string line;
	while(cin >> N) {
		vector<vector<int>> adj_matrix(N, vector<int>(N, plusINF));
		adj_matrix[0][0] = 0;
		for (int i = 1; i < N; i++) {
			adj_matrix[i][i] = 0;
			for (int j = 0; j < i; j++) {
				cin >> line;
				if (line[0] == 'x') continue;
				adj_matrix[i][j] = stoi(line);
				adj_matrix[j][i] = stoi(line);
			}
		}
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					adj_matrix[i][j] = min(adj_matrix[i][j], adj_matrix[i][k]+ adj_matrix[k][j]);
				}
			}
		}
		int res = 0;
		for (int i = 1; i < N; i++) {
			res = max(res, adj_matrix[0][i]);
		}
		cout << res << "\n";
	}
	return 0;
}
