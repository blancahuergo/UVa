#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<string, int> dict;
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
	int N, M, C, L;
	string A, B;
	vector<int> edge;
	vector<vector<int>> edges;
	while(true) {
		cin >> N >> M;
		if (!(N||M)) break;
		parent.assign(N, 0);
		rnk.assign(N, 0);
		dict.clear();
		for (int n = 0; n < N; n++) {
			cin >> A;
			dict[A] = n;
			parent[n] = n;
		}
		edges.clear();
		while(M--) {
			cin >> A >> B >> C;
			edges.push_back({C, dict[A], dict[B]});
		}
		cin >> A;
		if (dict.find(A) == dict.end()) {
			cout << "Impossible\n";
			continue;
		}
		sort(edges.begin(), edges.end());
		L = 0;
		numSets = N;
		edge.assign(3, 0);
		for (int l = 0; l < edges.size() and numSets > 1; l++) {
			edge = edges[l];
			if (isSameSet(edge[1], edge[2])) continue;
			mergeByRank(edge[1], edge[2]);
			L += edge[0];
		}
		if (numSets > 1) cout << "Impossible\n";
		else cout << L << endl;
	}
	return 0;
}
