#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> parent;
vector<int> rnk;
int numSets;

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
	int N, M, A, B, R;
	vector<vector<int>> edges;
	vector<int> edge;
	while(true) {
		cin >> N >> M;
		if (!(N||M)) break;
		edges.clear();
		parent.assign(N, 0);
		for (int n = 0; n < N; n++) parent[n] = n;
		rnk.assign(N, 0);
		numSets = N;
		while(M--) {
			cin >> A >> B >> R;
			edges.push_back({R, A, B});
		}
		sort(edges.begin(), edges.end());
		int L = 0;
		edge.assign(3, 0);
		bool pos = false;
		for (int l = 0; l < edges.size(); l++) {
			edge = edges[l];
			if (isSameSet(edge[1], edge[2])) continue;
			mergeByRank(edge[1], edge[2]);
			L = max(L, edge[0]);
			if (numSets == 1) {
				pos = true;
				break;
			}
		}
		if (pos) cout << L << endl;
		else cout << "IMPOSSIBLE\n";
	}
	return 0;
}
