#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	int t = 1, N, M;
	double rate;
	string cur, curA, curB;
	unordered_map<string, int> dict;
	while(true) {
		cin >> N;
		if (!N) break;
		dict.clear();
		for (int n = 0; n < N; n++) {
			cin >> cur;
			dict[cur] = n;
		}
		double adj_matrix[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j) adj_matrix[i][i] = 1.0;
				else adj_matrix[i][j] = 0.0;
			}
		}
		cin >> M;
		while(M--) {
			cin >> curA >> rate >> curB;
			adj_matrix[dict[curA]][dict[curB]] = max(rate, adj_matrix[dict[curA]][dict[curB]]);
		}
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					adj_matrix[i][j] = max(adj_matrix[i][k]*adj_matrix[k][j], adj_matrix[i][j]);
				}
			}
		}
		bool possible = false;
		for (int i = 0; i < N; i++) {
			if (adj_matrix[i][i] > 1.0) {
				possible = true;
				break;
			}
		}
		cout << "Case " << t << ": ";
		if (possible) cout << "Yes\n";
		else cout << "No\n";
		t++;
	}
	return 0;
}
