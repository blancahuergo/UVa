#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<bool> airport;
vector<vector<pair<int, int>>> adj_list;

int Dijkstra(int S, int D, int N) {
	vector<int> dist;
	dist.assign(N, 2000000000);
	dist[S] = !(airport[S]);
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
	int T, N, M, K, city, A, B, Q, ans;
	vector<pair<int, int>> empt;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> K;
		airport.assign(N, false);
		adj_list.assign(N, empt);
		for (int k = 0; k < K; k++) {
			cin >> city;
			airport[city-1] = true;
		}
		for (int m = 0; m < M; m++) {
			cin >> A >> B;
			A--;
			B--;
			if (airport[B])
				adj_list[A].push_back({B, 0});
			else
				adj_list[A].push_back({B, 1});
			if (airport[A])
				adj_list[B].push_back({A, 0});
			else
				adj_list[B].push_back({A, 1});
		}
		cin >> Q;
		cout << "Case " << t << ":\n";
		while(Q--) {
			cin >> A >> B;
			if (A == B && airport[A-1] == false) {
				cout << "0\n";
				continue;
			}
			ans = Dijkstra(A-1, B-1, N);
			if (ans == 2000000000) cout << "-1\n";
			else cout << ans << "\n";
		}
		cout << "\n";
	}
	return 0;
}
