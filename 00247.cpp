#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int N, M, numSCC, dfsCounter;
vector<int> dfsNum, dfsLow, S;
vector<vector<string>> SCCs;
vector<string> s_empt;
vector<bool> visited;
vector<vector<int>> adj_list;
unordered_map<string, int> dict;
unordered_map<int, string> dict_inv;

void SCC(int u) {
	dfsLow[u] = dfsNum[u] = dfsCounter++;
	S.push_back(u);
	visited[u] = true;
	int v;
	for (int i = 0; i < adj_list[u].size(); i++) {
		v = adj_list[u][i];
		if (dfsNum[v] == -1)
			SCC(v);
		if (visited[v])
			dfsLow[u] = min(dfsLow[u], dfsLow[v]);
	}
	if (dfsLow[u] == dfsNum[u]) {
		// u is root of scc
		SCCs.push_back(s_empt);
		SCCs[numSCC].push_back(dict_inv[u]);
		while(true) {
			v = S.back();
			S.pop_back();
			visited[v] = false;
			if (u == v) break;
			// add v to scc[u]
			SCCs[numSCC].push_back(dict_inv[v]);
		}
		numSCC++;
	}
}

int main() {
	string A, B;
	vector<int> empt;
	int c;
	int cas = 1;
	while(true) {
		cin >> N >> M;
		if (!(N||M)) break;
		adj_list.assign(N, empt);
		dict.clear();
		dict_inv.clear();
		SCCs.clear();
		c = 0;
		while(M--) {
			cin >> A >> B;
			if (dict.find(A) == dict.end()) {
				dict[A] = c;
				dict_inv[c] = A;
				c++;
			}
			if (dict.find(B) == dict.end()) {
				dict[B] = c;
				dict_inv[c] = B;
				c++;
			}
			adj_list[dict[A]].push_back(dict[B]);
		}
		visited.assign(N, false);
		dfsNum.assign(N, -1);
		dfsLow.assign(N, -1);
		numSCC = dfsCounter = 0;
		S.clear();
		for (int i = 0; i < N; i++) {
			if (dfsNum[i] == -1) SCC(i);
		}
		if (cas > 1) cout << "\n";
		cout << "Calling circles for data set " << cas << ":\n";
		for (int i = 0; i < numSCC; i++) {
			cout << SCCs[i][0];
			for (int j = 1; j < SCCs[i].size(); j++) {
				cout << ", " << SCCs[i][j];
			}
			cout << "\n";
		}
		cas++;
	}
	return 0;
}
