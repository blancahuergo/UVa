#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T, N1, N2;
	string A, B;
	cin >> T;
	vector<pair<int, int>> edges;
	while(T--) {
		cin >> N1;
		edges.clear();
		int maxN1 = 0;
		while(N1--) {
			cin >> A >> B;
			maxN1 = max(maxN1, max(A[0]-'A', B[0]-'A'));
			edges.push_back({A[0] - 'A', B[0] - 'A'});
		}
		maxN1++;
		bool adj_matrix1[maxN1][maxN1];
		for (int i = 0; i < maxN1; i++) {
			for (int j = 0; j < maxN1; j++) {
				if (i == j) adj_matrix1[i][i] = true;
				else adj_matrix1[i][j] = false;
			}
		}
		for (int i = 0; i < edges.size(); i++) {
			adj_matrix1[edges[i].first][edges[i].second] = true;
		}
		for (int k = 0; k < maxN1; k++) {
			for (int i = 0; i < maxN1; i++) {
				for (int j = 0; j < maxN1; j++) {
					adj_matrix1[i][j] = adj_matrix1[i][j] || (adj_matrix1[i][k] && adj_matrix1[k][j]);
				}
			}
		}
		cin >> N2;
		edges.clear();
		int maxN2 = 0;
		while (N2--) {
			cin >> A >> B;
			maxN2 = max(maxN2, max(A[0] - 'A', B[0] - 'A'));
			edges.push_back( { A[0] - 'A', B[0] - 'A' });
		}
		maxN2++;
		bool adj_matrix2[maxN2][maxN2];
		for (int i = 0; i < maxN2; i++)
			for (int j = 0; j < maxN2; j++) {
				if (i == j) adj_matrix2[i][i] = true;
				else adj_matrix2[i][j] = false;
			}
		for (int i = 0; i < edges.size(); i++) {
			adj_matrix2[edges[i].first][edges[i].second] = true;
		}
		for (int k = 0; k < maxN2; k++) {
			for (int i = 0; i < maxN2; i++) {
				for (int j = 0; j < maxN2; j++) {
					adj_matrix2[i][j] = adj_matrix2[i][j] || (adj_matrix2[i][k] && adj_matrix2[k][j]);
				}
			}
		}
		bool ans = (maxN1 == maxN2);
		if (ans) {
			for (int i = 0; i < maxN1; i++) {
				if (!ans) break;
				for (int j = 0; j < maxN2; j++) {
					if (adj_matrix1[i][j] != adj_matrix2[i][j]) {
						ans = false;
						break;
					}
				}
			}
		}
		if (ans) cout << "YES\n";
		else cout << "NO\n";
		if (T) cout << "\n";
	}
	return 0;
}
