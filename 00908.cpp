#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
	int N, K, x, y, z, wT, M, wM, l;
	vector<vector<int>> edges;
	vector<int> edge;
	edge.assign(3, 0);
	bool first = true;
	while(cin >> N) {
		parent.assign(N, 0);
		rnk.assign(N, 0);
		wT = 0;
		edges.clear();
		for (int n = 0; n < N-1; n++) {
			cin >> x >> y >> z;
			wT += z;
			parent[n] = n;
			edge[0] = z;
			edge[1] = x;
			edge[2] = y;
			edges.push_back(edge);
		}
		parent[N-1] = N-1;
		cin >> K;
		while(K--) {
			cin >> x >> y >> z;
			edge[0] = z;
			edge[1] = x;
			edge[2] = y;
			edges.push_back(edge);
		}
		cin >> M;
		while(M--) {
			cin >> x >> y >> z;
			edge[0] = z;
			edge[1] = x;
			edge[2] = y;
			edges.push_back(edge);
		}
		sort(edges.begin(), edges.end());
		l = 0;
		wM = 0;
		while(l < edges.size()) {
			if (isSameSet(edges[l][1], edges[l][2])) {
				l++;
				continue;
			}
			mergeByRank(edges[l][1], edges[l][2]);
			wM += edges[l][0];
			l++;
		}
		if (!first) cout << "\n";
		cout << wT << "\n" << wM << "\n";
		first = false;
	}
	return 0;
}
