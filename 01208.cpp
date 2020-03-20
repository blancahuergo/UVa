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
	int T, N, C;
	vector<int> edge;
	vector<vector<int>> edges;
	char ch;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);
		parent.assign(N, 0);
		rnk.assign(N, 0);
		numSets = N;
		edges.clear();
		for (int i = 0; i < N; i++) {
			parent[i] = i;
			for(int j = 0; j < N; j++) {
				scanf("%d%c", &C, &ch);
				if (C > 0 && j > i) edges.push_back({C, i, j});
			}
		}
		sort(edges.begin(), edges.end());
		cout << "Case " << t << ":\n";
		edge.assign(3, 0);
		for (int l = 0; l < edges.size(); l++) {
			edge = edges[l];
			if (isSameSet(edge[1], edge[2])) continue;
			mergeByRank(edge[1], edge[2]);
			cout << ((char) ('A' + min(edge[1], edge[2]))) << "-" << ((char) ('A' + max(edge[1], edge[2]))) << " " << edge[0] << endl;
			if (numSets == 1) break;
		}
	}
	return 0;
}
