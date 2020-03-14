#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj_matrix;

int main() {
	int T, N, R, u, v, S, D, res;
	vector<int> empt;
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		cin >> N >> R;
		empt.assign(N, 10000000);
		adj_matrix.assign(N, empt);
		for (int i = 0; i < N; i++) adj_matrix[i][i] = 0;
		for (int r = 0; r < R; r++) {
			cin >> u >> v;
			adj_matrix[u][v] = 1;
			adj_matrix[v][u] = 1;
		}
		cin >> S >> D;
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					adj_matrix[i][j] = min(adj_matrix[i][j], adj_matrix[i][k] + adj_matrix[k][j]);
				}
			}
		}
		res = 0;
		for (int i = 0; i < N; i++) {
			res = max(adj_matrix[S][i] + adj_matrix[i][D], res);
		}
		cout << "Case " << cas << ": " << res << endl;
	}
	return 0;
}
