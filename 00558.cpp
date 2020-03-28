#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> adj_list;

void BellmanFord(int S, int N) {
	vector<int> dist;
	dist.assign(N, 2000000000);
	dist[S] = 0;
	for(int i = 0; i < N-1; i++) {
		for (int u = 0; u < N; u++) {
			for (int j = 0; j < adj_list[u].size(); j++) {
				pair<int, int> v = adj_list[u][j];
				dist[v.first] = min(dist[v.first], dist[u]+v.second);
			}
		}
	}
	bool hasNegativeCycle = false;
	for (int u = 0; u < N; u++) {
		for (int j = 0; j < adj_list[u].size(); j++) {
			pair<int, int> v = adj_list[u][j];
			if (dist[v.first] > dist[u] + v.second) {
				hasNegativeCycle = true;
			}
		}
	}
	if (hasNegativeCycle) cout << "possible\n";
	else cout << "not possible\n";
}

int main() {
	int T, N, M, A, B, C;
	vector<pair<int, int>> empt;
	cin >> T;
	while(T--) {
		cin >> N >> M;
		adj_list.assign(N, empt);
		for (int m = 0; m < M; m++) {
			cin >> A >> B >> C;
			adj_list[A].push_back({B, C});
		}
		BellmanFord(0, N);
	}
	return 0;
}
