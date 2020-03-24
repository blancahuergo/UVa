#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int numSets;
vector<int> parent, rnk;

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
	int T, N, M, A, B, C, l, ans;
	vector<vector<int>> edges;
	vector<int> edge;
	cin >> T;
	while(T--) {
		cin >> N >> M;
		edges.clear();
		for (int m = 0; m < M; m++) {
			cin >> A >> B >> C;
			edges.push_back({-C, A-1, B-1});
		}
		sort(edges.begin(), edges.end());
		numSets = N;
		rnk.assign(N, 0);
		parent.assign(N, 0);
		for (int n = 0; n < N; n++) parent[n] = n;
		ans = 0;
		l = 0;
		while(l < M) {
			edge = edges[l];
			l++;
			if (isSameSet(edge[1], edge[2])) {
				ans += -edge[0];
				continue;
			}
			mergeByRank(edge[1], edge[2]);
		}
		cout << ans << "\n";
	}
	return 0;
}
