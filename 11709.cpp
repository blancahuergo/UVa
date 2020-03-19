#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

int N, M, numSCC, dfsCounter;
vector<int> dfsNum, dfsLow, S;
vector<bool> visited;
vector<vector<int>> adj_list;
unordered_map<string, int> dict;

void SCC(int u) {
	dfsLow[u] = dfsNum[u] = dfsCounter++;
	S.push_back(u);
	visited[u] = true;
	int v;
	for (int i = 0; i < adj_list[u].size(); i++) {
		v = adj_list[u][i];
		if (dfsNum[v] == -1)
			SCC(v);
		if (visited[v])
			dfsLow[u] = min(dfsLow[u], dfsLow[v]);
	}
	if (dfsLow[u] == dfsNum[u]) {
		while(true) {
			v = S.back();
			S.pop_back();
			visited[v] = false;
			if (u == v) break;
		}
		numSCC++;
	}
}

int main() {
	string A, B, nam;
	vector<int> empt;
	stringstream ss;
	int c;
	while(true) {
		ss.str("");
		ss.clear();
		getline(cin, nam);
		ss.str(nam);
		ss >> N;
		ss >> M;
		if (!(N||M)) break;
		adj_list.assign(N, empt);
		dict.clear();
		c = 0;
		for (int n = 0; n < N; n++) {
			getline(cin, nam);
			dict[nam] = c;
			c++;
		}
		while(M--) {
			getline(cin, A);
			getline(cin, B);
			adj_list[dict[A]].push_back(dict[B]);
		}
		visited.assign(N, false);
		dfsNum.assign(N, -1);
		dfsLow.assign(N, -1);
		numSCC = dfsCounter = 0;
		S.clear();
		for (int i = 0; i < N; i++) {
			if (dfsNum[i] == -1) SCC(i);
		}
		cout << numSCC << endl;
	}
	return 0;
}
