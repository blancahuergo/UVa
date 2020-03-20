#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> parent;
vector<int> rnk;
int numSets;
vector<string> combs;

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

int cost(int i, int j) {
	int tot = 0;
	for (int y = 0; y < 4; y++) tot += min(abs(combs[i][y] - combs[j][y]), 10 - abs(combs[i][y] - combs[j][y]));
	return tot;
}

int main() {
	int T, N;
	string comb;
	vector<vector<int>> edges;
	vector<int> edge;
	bool usedZ;
	cin >> T;
	while(T--) {
		cin >> N;
		combs.clear();
		edges.clear();
		edge.assign(3, 0);
		parent.assign(N+1, 0);
		rnk.assign(N+1, 0);
		numSets = N+1;
		for (int n = 0; n < N; n++) {
			cin >> comb;
			combs.push_back(comb);
			parent[n] = n;
		}
		combs.push_back("0000");
		parent[N] = N;
		for (int i = 0; i < N+1; i++) {
			for (int j = i+1; j < N+1; j++) {
				edges.push_back({cost(i, j), i, j});
			}
		}
		sort(edges.begin(), edges.end());
		int ans = 0;
		int l = 0;
		usedZ = false;
		while(numSets > 1) {
			edge = edges[l];
			if (isSameSet(edge[1], edge[2])) {
				l++;
				continue;
			}
			if (usedZ) {
				if (edge[1] == N || edge[2] == N) {
					l++;
					continue;
				}
			}
			ans += edge[0];
			mergeByRank(edge[1], edge[2]);
			//cout << combs[edge[1]] << " " << combs[edge[2]] << " " << edge[0] << endl;
			l++;
			if (edge[1] == N || edge[2] == N) usedZ = true;
		}
		cout << ans << endl;
	}
	return 0;
}
