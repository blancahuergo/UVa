#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int dfsCounter;
vector<int> dfsNum, dfsLow, dfsParent;
vector<vector<int>> adj_list;
vector<pair<int, int>> edges;

void artEdges(int u) {
	int v;
	dfsNum[u] = dfsLow[u] = dfsCounter++;
	for (int j = 0; j < adj_list[u].size(); j++) {
		v = adj_list[u][j];
		if (dfsNum[v] == -1) {
			dfsParent[v] = u;
			artEdges(v);
			if (dfsLow[v] > dfsNum[u]) edges.push_back(make_pair(min(u, v), max(u, v)));
			dfsLow[u] = min(dfsLow[u], dfsLow[v]);
		} else if (v != dfsParent[u])
			dfsLow[u] = min(dfsLow[u], dfsNum[v]);
	}
}

int main() {
	int N, u, v, num;
	vector<int> empt;
	while(scanf("%d", &N) == 1) {
		if (N == 0) {
			printf("0 critical links\n\n");
			continue;
		}
		adj_list.assign(N, empt);
		for (int n = 0; n < N; n++) {
			scanf("%d ", &u);
			scanf("(%d)", &num);
			while(num--) {
				scanf("%d", &v);
				adj_list[u].push_back(v);
				adj_list[v].push_back(u);
			}
		}
		dfsCounter = 0;
		dfsNum.assign(N, -1);
		dfsLow.assign(N, -1);
		dfsParent.assign(N, -1);
		edges.clear();
		for (int i = 0; i < N; i++)
			if (dfsNum[i] == -1) artEdges(i);
		printf("%d critical links\n", edges.size());
		if (edges.size() > 0) {
			sort(edges.begin(), edges.end());
			for (int i = 0; i < edges.size(); i++) {
				printf("%d - %d\n", edges[i].first, edges[i].second);
			}
		}
		printf("\n");
	}
	return 0;
}
