#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

unordered_map<string, int> dict;
int numSets, ans;
vector<int> parent, rnk, predec;
vector<vector<int>> adj_list;
vector<bool> visited;
string S, D;

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
	int N, M, C, c, cur;
	vector<vector<int>> edges, dist;
	vector<int> edge, empt, empt2;
	string A, B;
	int t = 1;
	while(true) {
		cin >> N >> M;
		if (!(N||M)) break;
		dict.clear();
		edges.clear();
		c = 0;
		while(M--) {
			cin >> A >> B >> C;
			if (dict.find(A) == dict.end()) {
				dict[A] = c;
				c++;
			}
			if (dict.find(B) == dict.end()) {
				dict[B] = c;
				c++;
			}
			edges.push_back({-C, dict[A], dict[B]});
		}
		cin >> S >> D;
		sort(edges.begin(), edges.end());
		numSets = N;
		rnk.assign(N, 0);
		parent.assign(N, 0);
		for (int n = 0; n < N; n++) parent[n] = n;
		int l = 0;
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
			dist[edge[1]][edge[2]] = -edge[0];
			dist[edge[2]][edge[1]] = -edge[0];
		}
		ans = 2000000000;
		predec.assign(N, 0);
		predec[dict[S]] = dict[S];
		visited.assign(N, false);
		DFS(dict[S]);
		cur = dict[D];
		while(predec[cur] != cur) {
			ans = min(ans, dist[predec[cur]][cur]);
			cur = predec[cur];
		}
		cout << "Scenario #" << t << "\n";
		cout << ans << " tons\n\n";
		t++;
	}
	return 0;
}
