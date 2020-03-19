#include <iostream>
#include <vector>
using namespace std;

int N, M, numSCC, dfsCounter;
vector<int> dfsNum, dfsLow, S;
vector<bool> visited;
vector<vector<int>> adj_list;

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
		numSCC++;
		while(true) {
			v = S.back();
			S.pop_back();
			visited[v] = false;
			if (u == v) break;
		}
	}
}

int main() {
	int A, B, D;
	vector<int> empt;
	while(true) {
		cin >> N >> M;
		if (!(N||M)) break;
		adj_list.assign(N, empt);
		while(M--) {
			cin >> A >> B >> D;
			adj_list[A-1].push_back(B-1);
			if (D == 2) adj_list[B-1].push_back(A-1);
		}
		visited.assign(N, false);
		dfsNum.assign(N, -1);
		dfsLow.assign(N, -1);
		numSCC = 0;
		dfsCounter = 0;
		S.clear();
		for (int i = 0; i < N; i++) {
			if (dfsNum[i] == -1) SCC(i);
		}
		if (numSCC > 1) cout << "0\n";
		else cout << "1\n";
	}
	return 0;
}
