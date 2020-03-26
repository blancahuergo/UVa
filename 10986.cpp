#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> adj_list;

int Dijkstra(int S, int D, int N) {
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
	return dist[D];
}

int main() {
	int T, N, M, S, D, A, B, C, ans;
	cin >> T;
	vector<pair<int, int>> empt;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> S >> D;
		adj_list.assign(N, empt);
		while(M--) {
			cin >> A >> B >> C;
			adj_list[A].push_back({B, C});
			adj_list[B].push_back({A, C});
		}
		ans = Dijkstra(S, D, N);
		if (ans == 2000000000) cout << "Case #" << t << ": unreachable\n";
		else cout << "Case #" << t << ": " << ans << "\n";
	}
	return 0;
}
