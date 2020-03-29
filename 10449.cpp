#include <iostream>
#include <vector>
using namespace std;

vector<long long> business;
vector<vector<pair<int, long long>>> adj_list;
vector<long long> dist;
long long plusINF = 2000000000000000, minusINF = -2000000000000000;


void BellmanFord(int S, int N) {
	dist.assign(N, plusINF);
	dist[S] = 0LL;
	for(int i = 0; i < N-1; i++) {
		for (int u = 0; u < N; u++) {
			for (int j = 0; j < adj_list[u].size(); j++) {
				pair<int, long long> v = adj_list[u][j];
				if (dist[u] != plusINF)
					dist[v.first] = min(dist[v.first], dist[u]+v.second);
			}
		}
	}
	bool hasNegativeCycle = false;
	for (int u = 0; u < N; u++) {
		for (int j = 0; j < adj_list[u].size(); j++) {
			pair<int, long long> v = adj_list[u][j];
			if (dist[u] != plusINF && dist[v.first] > dist[u] + v.second) {
				hasNegativeCycle = true;
				dist[v.first] = minusINF;
			}
		}
	}
}

int main() {
	int N, M, A, B, Q, x;
	vector<pair<int, long long>> empt;
	int t = 1;
	while(cin >> N) {
		adj_list.assign(N, empt);
		business.assign(N, 0LL);
		for (int n = 0; n < N; n++) {
			cin >> business[n];
		}
		cin >> M;
		while(M--) {
			cin >> A >> B;
			adj_list[A-1].push_back({B-1, (business[B-1]-business[A-1])*(business[B-1]-business[A-1])*(business[B-1]-business[A-1])});
		}
		cin >> Q;
		cout << "Set #" << t << "\n";
		BellmanFord(0, N);
		while(Q--) {
			cin >> x;
			x--;
			if (x < 0 || x >= N || dist[x] == plusINF || dist[x] < 3LL) cout << "?\n";
			else cout << dist[x] << "\n";
		}
		t++;
	}
	return 0;
}
