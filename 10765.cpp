#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dfsCounter, dfsRoot, rootChildren;
vector<int> dfsNum, dfsLow, dfsParent, CC;
vector<vector<int>> adj_list;
vector<pair<int, int>> result;

bool comp(pair<int, int> A, pair<int, int> B) {
	if (A.first > B.first) return true;
	else if (B.first < A.first) return false;
	else return A.second < B.second;
}


void artPoint(int u) {
	int v;
	dfsNum[u] = dfsLow[u] = dfsCounter++;
	for (int j = 0; j < adj_list[u].size(); j++) {
		v = adj_list[u][j];
		if (dfsNum[v] == -1) {
			dfsParent[v] = u;
			if (u == dfsRoot) rootChildren++;
			artPoint(v);
			if (dfsLow[v] >= dfsNum[u] && u != dfsRoot) {
				CC[u]++;
			}
			dfsLow[u] = min(dfsLow[u], dfsLow[v]);
		} else if (v != dfsParent[u])
			dfsLow[u] = min(dfsLow[u], dfsNum[v]);
	}
}

int main() {
	// pigeon value is the number of connected components in the graph if the station disappears
	int n, m, x, y, init_cc;
	vector<int> empt;
	while(true) {
		cin >> n >> m;
		adj_list.assign(n, empt);
		if (!(n||m)) break;
		while(true) {
			cin >> x >> y;
			if (x == -1) break;
			adj_list[x].push_back(y);
			adj_list[y].push_back(x);
		}
		dfsCounter = 0;
		dfsNum.assign(n, -1);
		dfsLow.assign(n, -1);
		dfsParent.assign(n, -1);
		CC.assign(n, 0);
		init_cc = 0;
		for (int i = 0; i < n; i++) {
			if (dfsNum[i] == -1) {
				dfsRoot = i;
				rootChildren = 0;
				artPoint(i);
				CC[i] = rootChildren-1;
				init_cc++;
			}
		}
		result.clear();
		for (int i = 0; i < n; i++) result.push_back(make_pair(CC[i], i));
		sort(result.begin(), result.end(), comp);
		for (int i = 0; i < m; i++) {
			cout << result[i].second << " " << init_cc + result[i].first << endl;
		}
		cout << "\n";
	}
	return 0;
}
