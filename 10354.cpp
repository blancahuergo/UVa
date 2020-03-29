#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> adj_list;
vector<vector<int>> adj_matrix;
vector<vector<int>> predec;
int plusINF = 1000000000;

void clear(int v, int N) {
	for (int i = 0; i < N; i++) {
		adj_matrix[i][v] = plusINF;
		adj_matrix[v][i] = plusINF;
	}
	for (int i = 0; i < predec[v].size(); i++) {
		clear(predec[v][i], N);
	}
}

void SSSP(int OF, int BH, int N) {
	vector<int> dist, empt;
	dist.assign(N, plusINF);
	predec.assign(N, empt);
	dist[OF] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, OF});
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
				predec[v].clear();
				predec[v].push_back(u);
				pq.push({dist[v], v});
			} else if (dist[u]+ed_v == dist[v]) {
				predec[v].push_back(u);
			}
		}
	}
	clear(BH, N);
}

int main() {
	int N, M, BH, OF, YH, Mar, A, B, C;
	vector<pair<int, int>> empt;
	vector<int> empt2;
	while(cin >> N >> M >> BH >> OF >> YH >> Mar) {
		adj_list.assign(N, empt);
		empt2.assign(N, plusINF);
		adj_matrix.assign(N, empt2);
		while(M--) {
			cin >> A >> B >> C;
			adj_list[A-1].push_back({B-1, C});
			adj_list[B-1].push_back({A-1, C});
			adj_matrix[A-1][B-1] = C;
			adj_matrix[B-1][A-1] = C;
		}
		BH--;
		OF--;
		YH--;
		Mar--;
		for (int i = 0; i < N; i++) adj_matrix[i][i] = 0;
		SSSP(OF, BH, N);
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					adj_matrix[i][j] = min(adj_matrix[i][j], adj_matrix[i][k]+adj_matrix[k][j]);
				}
			}
		}
		if (adj_matrix[YH][Mar] == plusINF) cout << "MISSION IMPOSSIBLE.\n";
		else cout << adj_matrix[YH][Mar] << "\n";
	}
	return 0;
}
