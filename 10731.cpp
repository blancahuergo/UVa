#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int N, M, numSCC, dfsCounter;
vector<int> dfsNum, dfsLow, S;
vector<vector<char>> SCCs;
vector<char> s_empt;
vector<bool> visited;
vector<vector<int>> adj_list;
unordered_map<char, int> dict;
unordered_map<int, char> dict_inv;

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
		// u is root of scc
		SCCs.push_back(s_empt);
		SCCs[numSCC].push_back(dict_inv[u]);
		while(true) {
			v = S.back();
			S.pop_back();
			visited[v] = false;
			if (u == v) break;
			// add v to scc[u]
			SCCs[numSCC].push_back(dict_inv[v]);
		}
		sort(SCCs[numSCC].begin(), SCCs[numSCC].end());
		numSCC++;
	}
}

int main() {
	string line;
	vector<int> empt;
	char lets[5];
	int c;
	int cas = 1;
	while(true) {
		getline(cin, line);
		M = stoi(line);
		if (!M) break;
		adj_list.clear();
		dict.clear();
		dict_inv.clear();
		SCCs.clear();
		c = 0;
		while(M--) {
			getline(cin, line);
			lets[0] = line[0];
			lets[1] = line[2];
			lets[2] = line[4];
			lets[3] = line[6];
			lets[4] = line[8];
			if (dict.find(line[10]) == dict.end()) {
				dict[line[10]] = c;
				dict_inv[c] = line[10];
				adj_list.push_back(empt);
				c++;
			}
			for (int i = 0; i < 5; i++) {
				if (line[10] == lets[i]) continue;
				if (dict.find(lets[i]) == dict.end()) {
					dict[lets[i]] = c;
					dict_inv[c] = lets[i];
					adj_list.push_back(empt);
					c++;
				}
				adj_list[dict[line[10]]].push_back(dict[lets[i]]);
			}
		}
		N = c;
		visited.assign(N, false);
		dfsNum.assign(N, -1);
		dfsLow.assign(N, -1);
		numSCC = dfsCounter = 0;
		S.clear();
		for (int i = 0; i < N; i++) {
			if (dfsNum[i] == -1) SCC(i);
		}
		if (cas > 1) cout << "\n";
		sort(SCCs.begin(), SCCs.end());
		for (int i = 0; i < numSCC; i++) {
			cout << SCCs[i][0];
			for (int j = 1; j < SCCs[i].size(); j++) {
				cout << " " << SCCs[i][j];
			}
			cout << "\n";
		}
		cas++;
	}
	return 0;
}
