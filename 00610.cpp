#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int dfsCounter, N, edges[1001][1001];
vector<int> dfsNum, dfsLow, dfsParent;
vector<vector<int>> adj_list;

void artEdges(int u) {
	dfsNum[u] = dfsLow[u] = dfsCounter++;
	for (int j = 0; j < adj_list[u].size(); j++) {
		int v = adj_list[u][j];
		if (dfsNum[v] == -1) {
			dfsParent[v] = u;
			artEdges(v);
			if (dfsLow[v] <= dfsNum[u]) {
				edges[v][u] = 0;
			}
			dfsLow[u] = min(dfsLow[u], dfsLow[v]);
		} else if (v != dfsParent[u]) {
			dfsLow[u] = min(dfsLow[u], dfsNum[v]);
			if (edges[u][v]) edges[v][u] = 0;
		}
	}
}

int main() {
	int M, u, v, cas = 1;
	vector<int> empt;
	while(true) {
		cin >> N >> M;
		if (!(N||M)) break;
		adj_list.assign(N, empt);
		memset(edges, 0, sizeof edges);
		while(M--) {
			cin >> u >> v;
			adj_list[u-1].push_back(v-1);
			adj_list[v-1].push_back(u-1);
			edges[u-1][v-1] = edges[v-1][u-1] = 1;
		}
		dfsCounter = 0;
		dfsNum.assign(N, -1);
		dfsLow.assign(N, -1);
		dfsParent.assign(N, -1);
		for (int i = 0; i < N; i++) {
			if (dfsNum[i] == -1) {
				dfsParent[i] = i;
				artEdges(i);
			}
		}
		cout << cas << "\n\n";
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (edges[i][j] >= 1) {
					cout << (i+1) << " " << (j+1) << endl;
					continue;
				}
			}
		}
		cout << "#" << endl;
		cas++;
	}
	return 0;
}
