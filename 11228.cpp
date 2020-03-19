#include <iostream>
#include <vector>
#include <cmath>
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
	int T, N, r, x, y, numStates;
	double roads, rails;
	vector<pair<double, double>> coords;
	vector<vector<double>> edges;
	vector<double> edge;
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		cin >> N >> r;
		coords.assign(N, make_pair(0, 0));
		parent.assign(N, 0);
		rnk.assign(N, 0);
		for (int n = 0; n < N; n++) {
			cin >> x >> y;
			coords[n].first = (double) x;
			coords[n].second = (double) y;
			parent[n] = n;
		}
		edges.clear();
		for (int i = 0; i < N; i++) {
			for (int j = i+1; j < N; j++) {
				edges.push_back({sqrt((coords[i].first - coords[j].first)*(coords[i].first - coords[j].first) + (coords[i].second - coords[j].second)*(coords[i].second - coords[j].second)), (double) i, (double) j});
			}
		}
		sort(edges.begin(), edges.end());
		numSets = N;
		numStates = N;
		roads = 0;
		rails = 0;
		for (int l = 0; l < edges.size(), numSets > 1; l++) {
			edge = edges[l];
			if (isSameSet((int) edge[1], (int) edge[2])) continue;
			if (edge[0] <= r) {
				roads += edge[0];
				numStates--;
			} else rails += edge[0];
			mergeByRank((int) edge[1], (int) edge[2]);
		}
		cout << "Case #" << cas << ": " << numStates << " " << ((long long) round(roads)) << " " << ((long long) round(rails)) << endl;
	}
	return 0;
}
