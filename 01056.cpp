#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
	int N, M, plusINF = 1000000000;
	string A, B;
	unordered_map<string, int> dict;
	int t = 1;
	while(true) {
		cin >> N >> M;
		if (!(N||M)) break;
		vector<vector<int>> adj_matrix(N, vector<int>(N, plusINF));
		dict.clear();
		int c = 0;
		while(M--) {
			cin >> A >> B;
			if (dict.find(A) == dict.end()) {
				dict[A] = c;
				c++;
			}
			if (dict.find(B) == dict.end()) {
				dict[B] = c;
				c++;
			}
			adj_matrix[dict[A]][dict[B]] = adj_matrix[dict[B]][dict[A]] = 1;
		}
		for (int k = 0; k < N; k++) {
			adj_matrix[0][0] = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					adj_matrix[i][j] = min(adj_matrix[i][j], adj_matrix[i][k]+adj_matrix[k][j]);
				}
			}
		}
		int record = 0;
		for (int i = 0; i < N; i++) {
			for (int j = i+1; j < N; j++) {
				record = max(record, adj_matrix[i][j]);
			}
		}
		if (record == plusINF) cout << "Network " << t << ": DISCONNECTED\n\n";
		else cout << "Network " << t << ": " << record << "\n\n";
		t++;
	}
	return 0;
}
