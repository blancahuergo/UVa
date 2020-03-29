#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> dict;
unordered_map<int, string> dict_inv;

int main() {
	int N, M, A, B, C, plusINF = 1000000000;
	string line;
	int t = 1;
	while(true) {
		cin >> N >> M;
		if (!(N||M)) break;
		vector<vector<int>> adj_matrix(N, vector<int>(N, plusINF));
		dict.clear();
		dict_inv.clear();
		for (int n = 0; n < N; n++) {
			cin >> line;
			dict[line] = n;
			dict_inv[n] = line;
			adj_matrix[n][n] = 0;
		}
		while(M--) {
			cin >> A >> B >> C;
			adj_matrix[A-1][B-1] = C;
			adj_matrix[B-1][A-1] = C;
		}
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					adj_matrix[i][j] = min(adj_matrix[i][j], adj_matrix[i][k]+adj_matrix[k][j]);
				}
			}
		}
		int min_sum=plusINF, max_home;
		for (int i = 0; i < N; i++) {
			int row_sum = 0;
			for (int j = 0; j< N; j++) {
				if (i == j) continue;
				row_sum += adj_matrix[i][j];
			}
			if (row_sum < min_sum) {
				min_sum = row_sum;
				max_home = i;
			}
		}
		cout << "Case #" << t << " : " << dict_inv[max_home] << "\n";
		t++;
	}
	return 0;
}
