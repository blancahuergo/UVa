#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
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
	cout << fixed << setprecision(2);
	int T, N;
	double x, y, dist;
	vector<pair<double, double>> coords;
	vector<vector<double>> edges;
	vector<double> edge;
	cin >> T;
	while(T--) {
		cin >> N;
		coords.assign(N, make_pair(0, 0));
		rnk.assign(N, 0);
		parent.assign(N, 0);
		edge.assign(3, 0);
		for (int n = 0; n < N; n++) {
			cin >> x >> y;
			coords[n].first = x;
			coords[n].second = y;
			parent[n] = n;
		}
		edges.clear();
		for (int i = 0; i < N; i++) {
			for (int j = i+1; j < N; j++) {
				edge[0] = (coords[i].first - coords[j].first)*(coords[i].first - coords[j].first) + (coords[i].second - coords[j].second)*(coords[i].second - coords[j].second);
				edge[1] = i;
				edge[2] = j;
				edges.push_back(edge);
			}
		}
		sort(edges.begin(), edges.end());
		dist = 0;
		numSets = N;
		int l = 0;
		while(numSets > 1) {
			edge = edges[l];
			l++;
			if (isSameSet((int) edge[1], (int) edge[2])) continue;
			dist += sqrt(edge[0]);
			mergeByRank((int) edge[1], (int) edge[2]);
		}
		cout << dist << endl;
		if (T) cout << "\n";
	}
	return 0;
}
