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
	int T, N, M, A, B, C, l, S1, S2, cur;
	vector<vector<int>> edges;
	vector<int> edge;
	vector<int> used;
	bool pos;
	cin >> T;
	while(T--) {
		cin >> N >> M;
		edges.clear();
		used.assign(M, 0);
		for (int m = 0; m < M; m++) {
			cin >> A >> B >> C;
			edges.push_back({C, A-1, B-1});
		}
		sort(edges.begin(), edges.end());
		numSets = N;
		rnk.assign(N, 0);
		parent.assign(N, 0);
		for (int n = 0; n < N; n++) parent[n] = n;
		l = 0;
		S1 = 0;
		while(numSets > 1) {
			edge = edges[l];
			l++;
			if (isSameSet(edge[1], edge[2])) continue;
			mergeByRank(edge[1], edge[2]);
			used[l-1] = 1;
			S1 += edge[0];
		}
		S2 = 2000000000;
		for (int flag = 0; flag < edges.size(); flag++) {
			if (!used[flag]) continue;
			numSets = N;
			for (int n = 0; n < N; n++) {
				parent[n] = n;
				rnk[n] = 0;
			}
			l = 0;
			cur = 0;
			pos = true;
			while(numSets > 1) {
				if (l >= M) {
					pos = false;
					break;
				}
				edge = edges[l];
				l++;
				if (l-1 == flag) continue;
				if (isSameSet(edge[1], edge[2])) continue;
				mergeByRank(edge[1], edge[2]);
				cur += edge[0];
			}
			if (pos) S2 = min(cur, S2);
		}
		cout << S1 << " " << S2 << "\n";
	}
	return 0;
}
