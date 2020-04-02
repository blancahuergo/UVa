#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<pair<double, double>> gopher, holes;
vector<vector<int>> adj_list;
vector<int> vis, match;
int G, H, t, v;
double maxD;

void buildG() {
	int curD;
	for (int g = 0; g < G; g++) {
		for (int h = 0; h < H; h++) {
			curD = sqrt((gopher[g].first - holes[h].first)*(gopher[g].first - holes[h].first) + (gopher[g].second - holes[h].second)*(gopher[g].second - holes[h].second));
			if (curD < maxD) {
				adj_list[g].push_back(G+h);
				adj_list[G+h].push_back(g);
			}
		}
	}
}

int Aug(int l) {
	if (vis[l]) return 0;
	vis[l] = 1;
	for (int j = 0; j < (int) adj_list[l].size(); j++) {
		int r = adj_list[l][j];
		if (match[r] == -1 || Aug(match[r])) {
			match[r] = l;
			return 1;
		}
	}
	return 0;
}

int main() {
	vector<int> empt;
	while(cin >> G >> H >> t >> v) {
		maxD = v*t;
		gopher.assign(G, {0, 0});
		adj_list.assign(G+H, empt);
		for (int g = 0; g < G; g++) {
			cin >> gopher[g].first >> gopher[g].second;
		}
		holes.assign(H, {0, 0});
		for (int h = 0; h < H; h++) {
			cin >> holes[h].first >> holes[h].second;
		}
		buildG();
		int MCBM = 0;
		match.assign(G+H, -1);
		for (int l = 0; l < G; l++) {
			vis.assign(G+H, 0);
			MCBM += Aug(l);
		}
		cout << (G-MCBM) << endl;
	}
	return 0;
}
