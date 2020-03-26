#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> grid;

int minSteps(int R, int C) {
	vector<int> dist;
	dist.assign(R*C, 2000000000);
	dist[0] = grid[0][0];
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({dist[0], 0});
	pair<int, int> cur, cur_v;
	int dis, u, v, ed_v;
	while(!pq.empty()) {
		cur = pq.top();
		pq.pop();
		dis = cur.first;
		u = cur.second;
		if (dis > dist[u]) continue;
		if (u - C > 0) {
			v = u - C;
			ed_v = grid[v/C][v%C];
			if (dist[u]+ed_v < dist[v]) {
				dist[v] = dist[u]+ed_v;
				pq.push({dist[v], v});
			}
		}
		if (u + C < R*C) {
			v = u + C;
			ed_v = grid[v/C][v%C];
			if (dist[u]+ed_v < dist[v]) {
				dist[v] = dist[u]+ed_v;
				pq.push({dist[v], v});
			}
		}
		if (u%C != 0) {
			v = u - 1;
			ed_v = grid[v/C][v%C];
			if (dist[u]+ed_v < dist[v]) {
				dist[v] = dist[u]+ed_v;
				pq.push({dist[v], v});
			}
		}
		if (u%C != C-1) {
			v = u + 1;
			ed_v = grid[v/C][v%C];
			if (dist[u]+ed_v < dist[v]) {
				dist[v] = dist[u]+ed_v;
				pq.push({dist[v], v});
			}
		}
	}
	return dist[R*C-1];
}

int main() {
	int T, R, C;
	vector<int> empt;
	cin >> T;
	while(T--) {
		cin >> R >> C;
		empt.assign(C, 0);
		grid.assign(R, empt);
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				cin >> grid[r][c];
			}
		}
		cout << minSteps(R, C) << "\n";
	}
	return 0;
}
