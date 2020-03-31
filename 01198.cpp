#include <iostream>
#include <sstream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
	int N, plusINF = 1000000000, num, Q;
	string line;
	stringstream ss;
	vector<int> input;
	unordered_set<int> found;
	while(getline(cin, line)) {
		N = stoi(line);
		int adj_matrix[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) adj_matrix[i][j] = plusINF;
		}
		for (int n = 0; n < N; n++) {
			adj_matrix[n][n] = 0;
			getline(cin, line);
			ss.str("");
			ss.clear();
			ss.str(line);
			while(ss >> num) {
				adj_matrix[n][num-1] = 1;
				adj_matrix[num-1][n] = 1;
			}
		}
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					adj_matrix[i][j] = min(adj_matrix[i][j], adj_matrix[i][k]+adj_matrix[k][j]);
				}
			}
		}
		getline(cin, line);
		Q = stoi(line);
		int u, v;
		while(Q--) {
			getline(cin, line);
			ss.str("");
			ss.clear();
			ss.str(line);
			input.clear();
			found.clear();
			while(ss >> num) input.push_back(num-1);
			for (int i = 0; i < (int) input.size(); i++) {
				u = input[i];
				found.insert(u);
				for (int j = i+1; j < (int) input.size(); j++) {
					v = input[j];
					if (adj_matrix[u][v] == 1) continue;
					for (int k = 0; k < N; k++) {
						if (u == k || v == k) continue;
						if (adj_matrix[u][k] + adj_matrix[k][v] == adj_matrix[u][v]) {
							found.insert(k);
						}
					}
				}
				if (found.size() == N) break;
			}
			if (found.size() == N) cout << "yes\n";
			else cout << "no\n";
		}
	}
	return 0;
}
