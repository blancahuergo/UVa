#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T, N, M, A, B, C, plusINF = 1000000000;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		vector<vector<int>> adj_matrix(N, vector<int>(N, plusINF));
		while(M--) {
			cin >> A >> B >> C;
			adj_matrix[B-1][A-1] = adj_matrix[A-1][B-1] = min(C, adj_matrix[A-1][B-1]);
		}
		for (int k = 0; k < N; k++) {
			adj_matrix[k][k] = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					adj_matrix[i][j] = min(adj_matrix[i][j], adj_matrix[i][k]+adj_matrix[k][j]);
				}
			}
		}
		int rec_dist = plusINF;
		bool possible;
		for (int S = 0; S < N; S++) {
			int dist = adj_matrix[0][S];
			possible = true;
			for (int j = 1; j < 5; j++) {
				if (adj_matrix[j][S] != dist) {
					possible = false;
					break;
				}
			}
			if (possible) {
				for (int j = 5; j < N; j++) {
					dist = max(dist, adj_matrix[j][S]);
				}
				rec_dist = min(dist, rec_dist);
			}
		}
		cout << "Map " << t << ": ";
		if (rec_dist != plusINF) cout << rec_dist << "\n";
		else cout << "-1\n";
	}
	return 0;
}
