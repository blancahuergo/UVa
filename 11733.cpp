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
	int T, N, M, A, X, Y, C, minCost, curCost, roads, air;
	vector<vector<int>> edges;
	vector<int> edge;
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		cin >> N >> M >> A;
		edges.clear();
		parent.assign(N, 0);
		for (int n = 0; n < N; n++) parent[n] = n;
		rnk.assign(N, 0);
		numSets = N;
		while(M--) {
			cin >> X >> Y >> C;
			edges.push_back({C, X-1, Y-1});
		}
		sort(edges.begin(), edges.end());
		edge.assign(3, 0);
		roads = 0;
		air = 0;
		minCost = A*N;
		for (int l = 0; l < edges.size(); l++) {
			edge = edges[l];
			if (isSameSet(edge[1], edge[2])) continue;
			mergeByRank(edge[1], edge[2]);
			roads += edge[0];
			curCost = A*numSets + roads;
			if (curCost < minCost) {
				minCost = curCost;
				air = numSets;
			}
		}
		cout << "Case #" << cas << ": " << minCost << " " << air << endl;
	}
	return 0;
}
