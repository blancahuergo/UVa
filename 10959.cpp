#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj_list;

void BFS(int N) {
	int u;
	queue<int> Q;
	vector<bool> visited;
	vector<int> dist;
	visited.assign(N, false);
	dist.assign(N, -1);
	dist[0] = 0;
	visited[0] = true;
	Q.push(0);
	while(!Q.empty()) {
		u = Q.front();
		Q.pop();
		for (int i = 0; i < adj_list[u].size(); i++) {
			if (!visited[adj_list[u][i]]) {
				visited[adj_list[u][i]] = true;
				dist[adj_list[u][i]] = dist[u]+1;
				Q.push(adj_list[u][i]);
			}
		}
	}
	for (int n = 1; n < N; n++) {
		cout << dist[n] << endl;
	}
}

int main() {
	int T, N, M, A, B;
	vector<int> empt;
	cin >> T;
	while(T--) {
		cin >> N >> M;
		adj_list.assign(N, empt);
		while(M--) {
			cin >> A >> B;
			adj_list[A].push_back(B);
			adj_list[B].push_back(A);
		}
		BFS(N);
		if (T) cout << "\n";
	}
	return 0;
}
