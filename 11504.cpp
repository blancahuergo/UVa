#include <iostream>
#include <vector>
using namespace std;

int N, M, numSCC, dfsCounter;
vector<int> dfsNum, dfsLow, S, empt, sccBel;
vector<bool> visited;
vector<vector<int>> adj_list, into, scc;

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
		scc.push_back(empt);
		scc[numSCC].push_back(u);
		sccBel[u] = numSCC;
		while(true) {
			v = S.back();
			S.pop_back();
			visited[v] = false;
			if (u == v) break;
			scc[numSCC].push_back(v);
			sccBel[v] = numSCC;
		}
		numSCC++;
	}
}

int main() {
	int T, A, B, res, u, v;
	cin >> T;
	while(T--) {
		cin >> N >> M;
		adj_list.assign(N, empt);
		into.assign(N, empt);
		while(M--) {
			cin >> A >> B;
			adj_list[A-1].push_back(B-1);
			into[B-1].push_back(A-1);
		}
		visited.assign(N, false);
		dfsNum.assign(N, -1);
		dfsLow.assign(N, -1);
		sccBel.assign(N, -1);
		numSCC = 0;
		dfsCounter = 0;
		scc.clear();
		S.clear();
		for (int i = 0; i < N; i++) {
			if (dfsNum[i] == -1) SCC(i);
		}
		res = numSCC;
		for (int i = 0; i < numSCC; i++) {
			bool ind = true;
			for (int j = 0; j < scc[i].size(); j++) {
				u = scc[i][j];
				for (int k = 0; k < into[u].size(); k++) {
					v = into[u][k];
					if (sccBel[u] != sccBel[v]) {
						ind = false;
						break;
					}
				}
				if (!ind) break;
			}
			if (!ind) res--;
		}
		cout << res << endl;
	}
	return 0;
}
