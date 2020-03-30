#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> seq;
unordered_map<int, string> dict_inv;
vector<vector<int>> parent;

void printPath(int i, int j) {
	if (i != j) printPath(i, parent[i][j]);
	seq.push_back(j);
}

int main() {
	int T, N, plusINF = 1000000000, Q;
	unordered_map<string, int> dict;
	string loc, S, D, nam;
	vector<int> empt;
	cin >> T;
	while(T--) {
		cin >> N;
		vector<vector<int>> adj_matrix(N, vector<int>(N, plusINF));
		empt.assign(N, 0);
		parent.assign(N, empt);
		dict.clear();
		dict_inv.clear();
		for (int n = 0; n < N; n++) {
			cin >> loc;
			dict[loc] = n;
			dict_inv[n] = loc;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> adj_matrix[i][j];
				if (adj_matrix[i][j] == -1) adj_matrix[i][j] = plusINF;
			}
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) parent[i][j] = i;
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (adj_matrix[i][k] >= 0 && adj_matrix[k][j] >= 0 && adj_matrix[i][k]+adj_matrix[k][j] < adj_matrix[i][j]) {
						adj_matrix[i][j] = adj_matrix[i][k]+adj_matrix[k][j];
						parent[i][j] = parent[k][j];
					}
				}
			}
		}
		cin >> Q;
		while(Q--) {
			cin >> nam >> S >> D;
			if (S == D && dict.find(S) != dict.end()) {
				cout << "Mr " << nam << " to go from " << S << " to " << D << ", you will receive " << adj_matrix[dict[S]][dict[D]] << " euros\n";
				if (parent[dict[S]][dict[S]] != dict[S]) {
					seq.clear();
					printPath(dict[S], parent[dict[S]][dict[S]]);
					seq.push_back(dict[S]);
					cout << "Path:" << dict_inv[seq[0]];
					for (int i = 1; i < seq.size(); i++) cout << " " << dict_inv[seq[i]];
					cout << "\n";
				} else cout << "Path:" << S << " " << D << "\n";
			} else if (dict.find(S) == dict.end() || dict.find(D) == dict.end() || adj_matrix[dict[S]][dict[D]] == plusINF) {
				cout << "Sorry Mr " << nam << " you can not go from " << S << " to " << D << "\n";
			} else {
				cout << "Mr " << nam << " to go from " << S << " to " << D << ", you will receive " << adj_matrix[dict[S]][dict[D]] << " euros\n";
				seq.clear();
				printPath(dict[S], dict[D]);
				cout << "Path:" << dict_inv[seq[0]];
				for (int i = 1; i < seq.size(); i++) cout << " " << dict_inv[seq[i]];
				cout << "\n";
			}
		}
	}
	return 0;
}
