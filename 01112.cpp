#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> adj_list;

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
	int tot = 0;
	for (int i = 0; i < N; i++) {
		if (dist[i] <= T) tot++;
	}
	return tot;
}

int main() {
	int cases, N, E, T, M, a, b, c;
	vector<pair<int, int>> empt;
	cin >> cases;
	while(cases--) {
		cin >> N >> E >> T;
		E--;
		cin >> M;
		adj_list.assign(N, empt);
		while(M--) {
			cin >> a >> b >> c;
			a--;
			b--;
			adj_list[b].push_back({a, c});
		}
		cout << Dijkstra(E, N, T) << "\n";
		if(cases) cout << "\n";
	}
	return 0;
}
