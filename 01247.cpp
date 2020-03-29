#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<string, int> dict;
unordered_map<int, string> dict_inv;
vector<vector<int>> parent;
vector<int> sol;

void printPath(int i, int j) {
	if (i != j) printPath(i, parent[i][j]);
	sol.push_back(j);
}

int main() {
	int N, M, C, plusINF = 1000000000;
	cin >> N >> M;
	string A, B;
	vector<vector<int>> adj_matrix;
	vector<int> empt, empt2;
	empt.assign(N, plusINF);
	empt2.assign(N, 0);
	adj_matrix.assign(N, empt);
	parent.assign(N, empt2);
	int n = 0;
	while(M--) {
		cin >> A >> B >> C;
		if (dict.find(A) == dict.end()) {
			dict[A] = n;
			dict_inv[n] = A;
			n++;
		}
		if (dict.find(B) == dict.end()) {
			dict[B] = n;
			dict_inv[n] = B;
			n++;
		}
		adj_matrix[dict[A]][dict[B]] = C;
		adj_matrix[dict[B]][dict[A]] = C;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			parent[i][j] = i;
		}
	}
	for (int k = 0; k < N; k++) {
		adj_matrix[k][k] = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (adj_matrix[i][k]+adj_matrix[k][j] < adj_matrix[i][j]) {
					adj_matrix[i][j] = adj_matrix[i][k]+adj_matrix[k][j];
					parent[i][j] = parent[k][j];
				}
			}
		}
	}
	int Q;
	cin >> Q;
	while(Q--) {
		cin >> A >> B;
		sol.clear();
		printPath(dict[A], dict[B]);
		cout << dict_inv[sol[0]];
		for (int i = 1; i < sol.size(); i++) {
			cout << " " << dict_inv[sol[i]];
		}
		cout << "\n";
	}
	return 0;
}
