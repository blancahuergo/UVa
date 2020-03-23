#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int numSets;
vector<int> parent;
vector<int> rnk;

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

int main() {
	int T, N, M, A, B, C, l;
	vector<vector<int>> edges;
	vector<int> edge;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		edges.clear();
		for (int m = 0; m < M; m++) {
			cin >> A >> B >> C;
			edges.push_back({-C, A, B});
		}
		numSets = N;
		rnk.assign(N, 0);
		parent.assign(N, 0);
		for (int n = 0; n < N; n++) parent[n] = n;
		sort(edges.begin(), edges.end());
		l = 0;
		while (numSets > 1) {
			edge = edges[l];
			l++;
			if (isSameSet(edge[1], edge[2])) continue;
			mergeByRank(edge[1], edge[2]);
		}
		cout << "Case #" << t << ": " << -edge[0] << "\n";
	}
	return 0;
}
