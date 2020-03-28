#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> adj_list;
vector<int> distDest;

int Dijkstra(int S, int N, int T) {
	vector<int> dist;
	dist.assign(N, 2000000000);
	dist[S] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, S});
	pair<int, int> cur, cur_v;
	int dis, u, v, ed_v;
	while(!pq.empty()) {
		cur = pq.top();
		pq.pop();
		dis = cur.first;
		u = cur.second;
		if (dis > dist[u]) continue;
		if (u <= T) {
			if (dist[T] > dist[u]+distDest[u]) dist[T] = dist[u]+distDest[u];
			continue;
		}
		for (int i = 0; i < adj_list[u].size(); i++) {
			cur_v = adj_list[u][i];
			v = cur_v.first;
			ed_v = cur_v.second;
			if (dist[u]+ed_v < dist[v]) {
				dist[v] = dist[u]+ed_v;
				pq.push({dist[v], v});
			}
		}
	}
	if (dist[T] == 2000000000) return -1;
	else return dist[T];
}

int main() {
	int N, M, K, C, U, V, P;
	vector<pair<int, int>> empt;
	while(true) {
		cin >> N >> M >> C >> K;
		if (!(N||M||K||C)) break;
		adj_list.assign(N, empt);
		vector<vector<int>> adj_matrix(N, vector<int>(N, 0));
		while(M--) {
			cin >> U >> V >> P;
			adj_list[U].push_back({V, P});
			adj_list[V].push_back({U, P});
			adj_matrix[U][V] = P;
			adj_matrix[V][U] = P;
		}
		distDest.assign(C, 0);
		for (int i = C-2; i >= 0; i--) {
			distDest[i] = distDest[i+1] + adj_matrix[i][i+1];
		}
		cout << Dijkstra(K, N, C-1) << endl;
	}
	return 0;
}
