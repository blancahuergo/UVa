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
	int N, M, x, y, z, W;
	vector<vector<int>> edges;
	bool forest;
	vector<int> res, edge = {0, 0, 0};
	while(true) {
		cin >> N >> M;
		if (!(N||M)) break;
		edges.clear();
		parent.assign(N, 0);
		rnk.assign(N, 0);
		for (int i = 0; i < N; i++) parent[i] = i;
		while(M--) {
			cin >> x >> y >> z;
			edge[1] = x;
			edge[2] = y;
			edge[0] = z;
			edges.push_back(edge);
		}
		sort(edges.begin(), edges.end());
		numSets = N;
		int l = 0;
		W = 0;
		res.clear();
		forest = true;
		while(l < edges.size()) {
			edge = edges[l];
			l++;
			if (isSameSet((int) edge[1], (int) edge[2])) {
				res.push_back(edge[0]);
				W += edge[0];
				forest = false;
				continue;
			}
			mergeByRank((int) edge[1], (int) edge[2]);
		}
		if (forest) cout << "forest" << endl;
		else {
			cout << res[0];
			for (int i = 1; i < res.size(); i++) cout << " " << res[i];
			cout << "\n";
		}
	}
	return 0;
}
