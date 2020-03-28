#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> adj_list;
vector<vector<int>> adj_matrix;
vector<vector<int>> pre;

void Dijkstra(int S, int N, int T) {
	vector<int> dist, empt;
	dist.assign(N, 2000000000);
	dist[S] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, S});
	pair<int, int> cur, cur_v;
	int dis, u, v, ed_v;
	pre.assign(N, empt);
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
				pre[v].clear();
				pre[v].push_back(u);
			} else if (dist[u]+ed_v == dist[v]) {
				pre[v].push_back(u);
			}
		}
	}
}

void deleteShortest(int T) {
	int v;
	for (int i = 0; i < pre[T].size(); i++) {
		v = pre[T][i];
		adj_matrix[v][T] = 0;
		deleteShortest(v);
	}
}

int FinalPath(int S, int N, int T) {
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
			if (adj_matrix[u][v] != ed_v) continue;
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
	int N, M, S, D, A, B, C;
	vector<int> empt2;
	vector<pair<int, int>> empt;
	while(true) {
		cin >> N >> M;
		if (!(N||M)) break;
		adj_list.assign(N, empt);
		empt2.assign(N, 2000000000);
		adj_matrix.assign(N, empt2);
		cin >> S >> D;
		while(M--) {
			cin >> A >> B >> C;
			adj_list[A].push_back({B, C});
			adj_matrix[A][B] = min(adj_matrix[A][B], C);
		}
		Dijkstra(S, N, D);
		deleteShortest(D);
		cout << FinalPath(S, N, D) << "\n";
	}
	return 0;
}
