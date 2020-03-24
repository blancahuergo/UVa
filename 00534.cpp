#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int numSets;
vector<int> parent, rnk, predec;
vector<vector<int>> adj_list;
vector<bool> visited;

int root(int a) {
	if (parent[a] != a) parent[a] = root(parent[a]);
	return parent[a];
}

bool isSameSet(int a, int b) {
	return root(a) == root(b);
}

void mergeByRank(int a, int b) {
	int r_a, r_b;
	r_a = root(a);
	r_b = root(b);
	if (r_a == r_b) return;
	numSets--;
	if (rnk[r_a] > rnk[r_b]) {
		parent[r_b] = r_a;
	} else if (rnk[r_b] > rnk[r_a]) {
		parent[r_a] = r_b;
	} else {
		parent[r_a] = r_b;
		rnk[r_b]++;
	}
}

void DFS(int u) {
	int v;
	visited[u] = true;
	for (int j = 0; j < adj_list[u].size(); j++) {
		v = adj_list[u][j];
		if (!visited[v]) {
			predec[v] = u;
			DFS(v);
		}
	}
}

int main() {
	cout << fixed << setprecision(3);
	int N, x, y, l, ans, cur;
	vector<pair<int, int>> points;
	vector<vector<int>> edges, dist;
	vector<int> edge, empt, empt2;
	int t = 1;
	while(true) {
		cin >> N;
		if (!N) break;
		points.clear();
		for (int n = 0; n < N; n++) {
			cin >> x >> y;
			points.push_back({x, y});
		}
		edges.clear();
		parent.assign(N, 0);
		for (int i = 0; i < N; i++) {
			parent[i] = i;
			for (int j = i+1; j < N; j++) {
				edges.push_back({(points[i].first-points[j].first)*(points[i].first-points[j].first) + (points[i].second-points[j].second)*(points[i].second-points[j].second), i, j});
			}
		}
		sort(edges.begin(), edges.end());
		numSets = N;
		rnk.assign(N, 0);
		l = 0;
		adj_list.assign(N, empt);
		empt2.assign(N, 0);
		dist.assign(N, empt2);
		while(numSets > 1) {
			edge = edges[l];
			l++;
			if (isSameSet(edge[1], edge[2])) continue;
			mergeByRank(edge[1], edge[2]);
			adj_list[edge[1]].push_back(edge[2]);
			adj_list[edge[2]].push_back(edge[1]);
			dist[edge[1]][edge[2]] = edge[0];
			dist[edge[2]][edge[1]] = edge[0];
		}
		predec.assign(N, 0);
		predec[0] = 0;
		visited.assign(N, false);
		DFS(0);
		cur = 1;
		ans = 0;
		while(predec[cur] != cur) {
			ans = max(ans, dist[predec[cur]][cur]);
			cur = predec[cur];
		}
		cout << "Scenario #" << t << "\n";
		cout << "Frog Distance = " << sqrt((double) ans) << "\n\n";
		t++;
	}
	return 0;
}
