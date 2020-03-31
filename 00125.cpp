#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


int main() {
	int T = 0, M, a, b, maxN;
	vector<pair<int, int>> edges;
	while(cin >> M) {
		edges.clear();
		maxN = 0;
		while(M--) {
			cin >> a >> b;
			edges.push_back({a, b});
			maxN = max(maxN, max(a, b));
		}
		maxN++;
		int adj_matrix[maxN][maxN];
		memset(adj_matrix, 0, sizeof adj_matrix);
		for (int i = 0; i < edges.size(); i++) adj_matrix[edges[i].first][edges[i].second] = 1;
		for (int k = 0; k < maxN; k++) {
			for (int i = 0; i < maxN; i++) {
				for (int j = 0; j < maxN; j++) {
					if (adj_matrix[i][k] && adj_matrix[k][j]) {
						adj_matrix[i][j] += adj_matrix[i][k]*adj_matrix[k][j];
					}
				}
			}
		}
		for (int k = 0; k < maxN; k++) {
			if (adj_matrix[k][k]) {
				for (int i = 0; i < maxN; i++) {
					for (int j = 0; j < maxN; j++) {
						if (adj_matrix[i][k] && adj_matrix[k][j]) {
							adj_matrix[i][j] = -1;
						}
					}
				}
			}
		}
		cout << "matrix for city " << T << "\n";
		for (int i = 0; i < maxN; i++) {
			cout << adj_matrix[i][0];
			for (int j = 1; j < maxN; j++) {
				cout << " " << adj_matrix[i][j];
			}
			cout << "\n";
		}
		T++;
	}
	return 0;
}
