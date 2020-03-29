#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	// No more than K edges
	int K, M, x_init, y_init, r_init, x_dest, y_dest, r_dest, N, x_cur, y_cur, r_cur;
	vector<vector<int>> islands;
	vector<vector<double>> adj_matrix;
	vector<double> empt;
	double plusINF = 1000000000000;
	while(cin >> K >> M) {
		cin >> x_init >> y_init >> r_init;
		cin >> x_dest >> y_dest >> r_dest;
		cin >> N;
		islands.clear();
		islands.push_back({x_init, y_init, r_init});
		for (int n = 0; n < N; n++) {
			cin >> x_cur >> y_cur >> r_cur;
			islands.push_back({x_cur, y_cur, r_cur});
		}
		islands.push_back({x_dest, y_dest, r_dest});
		N+=2;
		empt.assign(N, plusINF);
		adj_matrix.assign(N, empt);
		for (int i = 0; i < N; i++) {
			adj_matrix[i][i] = 0;
			for (int j = i+1; j < N; j++) {
				adj_matrix[i][j] = sqrt((double) ((islands[i][0] - islands[j][0])*(islands[i][0] - islands[j][0]) + (islands[i][1] - islands[j][1])*(islands[i][1] - islands[j][1]))) - islands[i][2] - islands[j][2];
				adj_matrix[j][i] = adj_matrix[i][j];
				if (adj_matrix[i][j] > K*M) {
					adj_matrix[i][j] = adj_matrix[j][i] = plusINF;
				}
			}
		}
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					adj_matrix[i][j] = min(adj_matrix[i][j], adj_matrix[i][k]+adj_matrix[k][j]);
				}
			}
		}
		if (adj_matrix[0][N-1] == plusINF) cout << "Larry and Ryan will be eaten to death.\n";
		else cout << "Larry and Ryan will escape!\n";
	}
	return 0;
}
