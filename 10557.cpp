#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> energy;
vector<vector<int>> adj_list;

void BellmanFord(int S, int N) {
	vector<int> dist;
	dist.assign(N, 2000000000);
	dist[S] = -100;
	for(int i = 0; i < N-1; i++) {
		for (int u = 0; u < N; u++) {
			for (int j = 0; j < adj_list[u].size(); j++) {
				int v = adj_list[u][j];
				if (dist[u] + energy[v] >= 0) continue;
				dist[v] = min(dist[v], dist[u]+energy[v]);
			}
		}
	}
	if (dist[N-1] < 0) {
		cout << "winnable\n";
		return;
	}
	bool hasPositiveCycle = false;
	int inCycle = 0;
	for (int u = 0; u < N; u++) {
		for (int j = 0; j < adj_list[u].size(); j++) {
			int v = adj_list[u][j];
			if (dist[u] + energy[v] >= 0) continue;
			if (dist[v] > dist[u] + energy[v]) {
				hasPositiveCycle = true;
				inCycle = u;
			}
		}
	}
	vector<bool> visited;
	visited.assign(N, false);
	queue<int> Q;
	Q.push(inCycle);
	visited.assign(N, false);
	visited[inCycle] = true;
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for (int i = 0; i < adj_list[u].size(); i++) {
			if (!visited[adj_list[u][i]]) {
				visited[adj_list[u][i]] = true;
				Q.push(adj_list[u][i]);
			}
		}
	}
	if (hasPositiveCycle && visited[N-1]) cout << "winnable\n";
	else cout << "hopeless\n";
}

int main() {
	int N, M, r;
	vector<int> empt;
	while(true) {
		cin >> N;
		if (N == -1) break;
		energy.assign(N, 0);
		adj_list.assign(N, empt);
		for (int n = 0; n < N; n++) {
			cin >> energy[n];
			energy[n] = -energy[n];
			cin >> M;
			while(M--) {
				cin >> r;
				adj_list[n].push_back(r-1);
			}
		}
		BellmanFord(0, N);
	}
	return 0;
}
