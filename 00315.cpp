#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int dfsCounter, dfsRoot, rootChildren;
vector<int> dfsNum, dfsLow, dfsParent;
vector<bool> artV;
vector<vector<int>> adj_list;

void artPoint(int u) {
	int v;
	dfsNum[u] = dfsLow[u] = dfsCounter++;
	for (int j = 0; j < adj_list[u].size(); j++) {
		v = adj_list[u][j];
		if (dfsNum[v] == -1) {
			dfsParent[v] = u;
			if (u == dfsRoot) rootChildren++;
			artPoint(v);
			if (dfsLow[v] >= dfsNum[u] && u != dfsRoot)
				artV[u] = true;
			dfsLow[u] = min(dfsLow[u], dfsLow[v]);
		} else if (v != dfsParent[u])
			dfsLow[u] = min(dfsLow[u], dfsNum[v]);
	}
}

int main() {
	int N, u, v;
	vector<int> empt;
	string line;
	stringstream ss;
	while(true) {
		getline(cin, line);
		N = stoi(line);
		if (!N) break;
		adj_list.assign(N, empt);
		while(true) {
			getline(cin, line);
			if (line[0] == '0') break;
			ss.str("");
			ss.clear();
			ss.str(line);
			ss >> u;
			u--;
			while(ss >> v) {
				adj_list[u].push_back(v-1);
				adj_list[v-1].push_back(u);
			}
		}
		dfsCounter = 0;
		dfsNum.assign(N, -1);
		dfsLow.assign(N, -1);
		dfsParent.assign(N, -1);
		artV.assign(N, false);
		for (int i = 0; i < N; i++) {
			if (dfsNum[i] == -1) {
				dfsRoot = i;
				rootChildren = 0;
				artPoint(dfsRoot);
				if (rootChildren > 1) artV[i] = true;
			}
		}
		cout << count(artV.begin(), artV.end(), true) << endl;
	}
	return 0;
}
