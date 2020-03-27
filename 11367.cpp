#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> prices;
vector<vector<pair<int, int>>> adj_list;

int Dijkstra(int S, int D, int N, int F) {
	vector<vector<int>> cost; // cost[location][fuel]
	vector<int> empt;
	empt.assign(F+1, 2000000000);
	cost.assign(N, empt);
	cost[S][0] = 0;
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	pq.push({0, S, 0});
	// {cost, location, fuel}
	vector<int> cur;
	pair<int, int> cur_v;
	int u, cost_u, fuel_u, v, ed_v;
	while(!pq.empty()) {
		cur = pq.top();
		pq.pop();
		cost_u = cur[0];
		u = cur[1];
		fuel_u = cur[2];
		if (cost_u > cost[u][fuel_u]) continue;
		if (fuel_u < F && cost_u+prices[u] < cost[u][fuel_u+1]) {
			cost[u][fuel_u+1] = cost_u+prices[u];
			pq.push({cost[u][fuel_u+1], u, fuel_u+1});
		}
		for (int i = 0; i < adj_list[u].size(); i++) {
			cur_v = adj_list[u][i];
			v = cur_v.first;
			ed_v = cur_v.second;
			if (ed_v > fuel_u) continue;
			if (cost[u][fuel_u] < cost[v][fuel_u - ed_v]) {
				cost[v][fuel_u - ed_v] = cost[u][fuel_u];
				pq.push({cost[v][fuel_u - ed_v], v, fuel_u - ed_v});
			}
		}
	}
	int ans = 2000000000;
	for (int f = 0; f <= F; f++) ans = min(ans, cost[D][f]);
	return ans;
}

int main() {
	int N, M, Q, F, S, D, A, B, C, ans;
	vector<pair<int,int>> empt;
	cin >> N >> M;
	prices.assign(N, 0);
	adj_list.assign(N, empt);
	for (int n = 0; n < N; n++) cin >> prices[n];
	while(M--) {
		cin >> A >> B >> C;
		adj_list[A].push_back({B, C});
		adj_list[B].push_back({A, C});
	}
	cin >> Q;
	while(Q--) {
		cin >> F >> S >> D;
		ans = Dijkstra(S, D, N, F);
		if (ans == 2000000000) cout << "impossible\n";
		else cout << ans << "\n";
	}
	return 0;
}
