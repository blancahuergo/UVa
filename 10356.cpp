#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> adj_list;

int Dijkstra(int N) {
	vector<vector<int>> dist(N, vector<int>(2, 2000000000)); // dist[junction][cycle]
	dist[0][1] = 0;
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	pq.push({0, 0, 1}); // [dist, junction, cycle]
	vector<int> cur;
	int u, dist_u, cyc_u, v, ed_v;
	while(!pq.empty()) {
		cur = pq.top();
		pq.pop();
		u = cur[1];
		dist_u = cur[0];
		cyc_u = cur[2];
		if (dist_u > dist[u][cyc_u]) continue;
		for (int i = 0; i < adj_list[u].size(); i++) {
			v = adj_list[u][i].first;
			ed_v = adj_list[u][i].second;
			if (dist[u][cyc_u] + ed_v < dist[v][1-cyc_u]) {
				dist[v][1-cyc_u] = dist[u][cyc_u] + ed_v;
				pq.push({dist[v][1-cyc_u], v, 1-cyc_u});
			}
		}
	}
	return dist[N-1][1];
}

int main() {
	int N, M, A, B, C;
	vector<pair<int,int>> empt;
	int cas = 1;
	while(cin >> N >> M) {
		adj_list.assign(N, empt);
		while(M--) {
			cin >> A >> B >> C;
			adj_list[A].push_back({B, C});
			adj_list[B].push_back({A, C});
		}
		cout << "Set #" << cas << "\n";
		int ans = Dijkstra(N);
		if (ans == 2000000000) cout << "?\n";
		else cout << ans << "\n";
		cas++;
	}
	return 0;
}
