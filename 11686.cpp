#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> adj_list;
vector<int> inv;
vector<bool> visited;
vector<int> TS;

int main() {
	int i, j, V;
	vector<int> empt;
	queue<int> Q, empty;
	while(true) {
		cin >> N >> M;
		if (!(N||M)) break;
		inv.assign(N, 0);
		adj_list.assign(N, empt);
		visited.assign(N, false);
		for (int m = 0; m < M; m++) {
			cin >> i >> j;
			adj_list[i-1].push_back(j-1);
			inv[j-1]++;
		}
		TS.clear();
		Q = empty;
		for (int k = 0; k < N; k++) {
			if (inv[k] == 0) Q.push(k);
		}
		while(! Q.empty()) {
			V = Q.front();
			TS.push_back(V+1);
			Q.pop();
			for (int k = 0; k < adj_list[V].size(); k++) {
				inv[adj_list[V][k]]--;
				if (inv[adj_list[V][k]] == 0) {
					Q.push(adj_list[V][k]);
				}
			}
		}
		if (TS.size() != N) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		for (int i = 0; i < N; i++) {
			cout << TS[i] << endl;
		}
	}
	return 0;
}
