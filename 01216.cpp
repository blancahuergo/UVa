#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
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
	int T, K, N, x, y, l;
	double cost;
	vector<pair<double, double>> points;
	vector<vector<double>> edges;
	vector<double> edge;
	cin >> T;
	while(T--) {
		cin >> K;
		N = 0;
		points.clear();
		while(true) {
			cin >> x;
			if (x == -1) break;
			cin >> y;
			N++;
			points.push_back(make_pair(x, y));
		}
		edges.clear();
		for (int i = 0; i < N; i++) {
			for (int j = i+1; j < N; j++) {
				edges.push_back({(points[i].first - points[j].first)*(points[i].first - points[j].first) + (points[i].second - points[j].second)*(points[i].second - points[j].second), (double) i, (double) j});
			}
		}
		sort(edges.begin(), edges.end());
		numSets = N;
		parent.assign(N, 0);
		for (int n = 0; n < N; n++) parent[n] = n;
		rnk.assign(N, 0);
		l = 0;
		cost = 0;
		while(numSets > K) {
			edge = edges[l];
			l++;
			if (isSameSet((int) edge[1], (int) edge[2])) continue;
			mergeByRank((int) edge[1], (int) edge[2]);
			cost = max(cost, sqrt(edge[0]));
		}
		cout << ((int) ceil(cost)) << "\n";
	}
	return 0;
}
