#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int numSets;
vector<int> parent;
vector<int> rnk;
vector<int> size;

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
	cout << fixed << setprecision(2);
	int N, x, y, M, A, B;
	double cost;
	vector<pair<int, int>> points;
	vector<vector<int>> edges;
	vector<int> edge;
	while(cin >> N) {
		points.clear();
		numSets = N;
		parent.assign(N, 0);
		rnk.assign(N, 0);
		for (int n = 0; n < N; n++) {
			cin >> x >> y;
			points.push_back(make_pair(x, y));
			parent[n] = n;
		}
		edges.clear();
		for (int i = 0; i < N; i++) {
			for (int j = i+1; j < N; j++) {
				edges.push_back({(points[i].first - points[j].first)*(points[i].first - points[j].first) + (points[i].second - points[j].second)*(points[i].second - points[j].second), i, j});
			}
		}
		cin >> M;
		while(M--) {
			cin >> A >> B;
			mergeByRank(A-1, B-1);
		}
		sort(edges.begin(), edges.end());
		int l = 0;
		cost = 0;
		while(numSets > 1) {
			edge = edges[l];
			l++;
			if (isSameSet(edge[1], edge[2])) continue;
			mergeByRank(edge[1], edge[2]);
			cost += sqrt((double) edge[0]);
		}
		cout << cost << endl;
	}
	return 0;
}
