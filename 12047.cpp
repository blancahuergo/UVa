#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> adj_list, rev_list;
vector<long long> distF, distB;
long long linf = 9000000000000000000LL;

void DijkstraSource(int s, int N) {
	distF.assign(N, linf);
	distF[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, s});
	pair<int, int> cur, cur_v;
	int dis, u, v, ed_v;
	while(!pq.empty()) {
		cur = pq.top();
		pq.pop();
		dis = cur.first;
		u = cur.second;
		if (dis > distF[u]) continue;
		for (int i = 0; i < adj_list[u].size(); i++) {
			cur_v = adj_list[u][i];
			v = cur_v.first;
			ed_v = cur_v.second;
			if (distF[u]+ed_v < distF[v]) {
				distF[v] = distF[u]+ed_v;
				pq.push({distF[v], v});
			}
		}
	}
}

void DijkstraDest(int t, int N) {
	distB.assign(N, linf);
	distB[t] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, t});
	pair<int, int> cur, cur_v;
	int dis, u, v, ed_v;
	while(!pq.empty()) {
		cur = pq.top();
		pq.pop();
		dis = cur.first;
		u = cur.second;
		if (dis > distB[u]) continue;
		for (int i = 0; i < rev_list[u].size(); i++) {
			cur_v = rev_list[u][i];
			v = cur_v.first;
			ed_v = cur_v.second;
			if (distB[u]+ed_v < distB[v]) {
				distB[v] = distB[u]+ed_v;
				pq.push({distB[v], v});
			}
		}
	}
}

int main() {
	int T, N, M, s, t, p, u, v, c;
	vector<pair<int, int>> empt;
	cin >> T;
	while(T--) {
		cin >> N >> M >> s >> t >> p;
		adj_list.assign(N, empt);
		rev_list.assign(N, empt);
		while(M--) {
			cin >> u >> v >> c;
			u--;
			v--;
			adj_list[u].push_back({v, c});
			rev_list[v].push_back({u, c});
		}
		s--;
		t--;
		DijkstraSource(s, N);
		if (distF[t] == linf) {
			cout << "-1\n";
			continue;
		}
		DijkstraDest(t, N);
		long long cur;
		int res = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < adj_list[i].size(); j++) {
				int w = adj_list[i][j].first;
				if (distF[i] == linf || distB[w] == linf) continue;
				cur = distF[i] + adj_list[i][j].second + distB[w];
				if (cur <= p) res = max(res, adj_list[i][j].second);
			}
		}
		cout << res << "\n";
	}
	return 0;
}
