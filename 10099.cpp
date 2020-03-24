#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
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
	int N, M, A, B, C, l, S, D, T, ans, cur;
	vector<vector<int>> edges, dist;
	vector<int> edge, empt, empt2;
	int t = 1;
	while(true) {
		cin >> N >> M;
		if (!(N||M)) break;
		edges.clear();
		for (int m = 0; m < M; m++) {
			cin >> A >> B >> C;
			edges.push_back({-C, A-1, B-1});
		}
		cin >> S >> D >> T;
		S--;
		D--;
		sort(edges.begin(), edges.end());
		numSets = N;
		parent.assign(N, 0);
		for (int n = 0; n < N; n++) parent[n] = n;
		rnk.assign(N, 0);
		empt2.assign(N, 0);
		adj_list.assign(N, empt);
		dist.assign(N, empt2);
		visited.assign(N, false);
		l = 0;
		while(numSets > 1) {
			edge = edges[l];
			l++;
			if (isSameSet(edge[1], edge[2])) continue;
			mergeByRank(edge[1], edge[2]);
			dist[edge[1]][edge[2]] = -edge[0];
			dist[edge[2]][edge[1]] = -edge[0];
			adj_list[edge[1]].push_back(edge[2]);
			adj_list[edge[2]].push_back(edge[1]);
		}
		ans = 2000000000;
		predec.assign(N, 0);
		predec[S] = S;
		DFS(S);
		cur = D;
		while(predec[cur] != cur) {
			ans = min(ans, dist[predec[cur]][cur]);
			cur = predec[cur];
		}
		cout << "Scenario #" << t << "\n";
		cout << "Minimum Number of Trips = " << ((int) ceil((double) T / (double) (ans-1))) << "\n\n";
		t++;
	}
	return 0;
}
