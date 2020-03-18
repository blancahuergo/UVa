#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

unordered_map<string, int> dict;
unordered_map<int, string> dict_inv;
int dfsCounter, dfsRoot, rootChildren;
vector<int> dfsNum, dfsLow, dfsParent;
vector<string> vertices;
vector<bool> artV;
vector<vector<int>> adj_list;

int count(int N) {
	vertices.clear();
	for (int i = 0; i < N; i++) {
		if (artV[i]) vertices.push_back(dict_inv[i]);
	}
	return (int) vertices.size();
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
			if (dfsLow[v] >= dfsNum[u] && u != dfsRoot)
				artV[u] = true;
			dfsLow[u] = min(dfsLow[u], dfsLow[v]);
		} else if (v != dfsParent[u])
			dfsLow[u] = min(dfsLow[u], dfsNum[v]);
	}
}

int main() {
	int N, M, cas = 1, ans;
	string loc, A, B;
	vector<int> empt;
	while(true) {
		cin >> N;
		if (!N) break;
		for (int n = 0; n < N; n++) {
			cin >> loc;
			dict[loc] = n;
			dict_inv[n] = loc;
		}
		cin >> M;
		adj_list.assign(N, empt);
		while(M--) {
			cin >> A >> B;
			adj_list[dict[A]].push_back(dict[B]);
			adj_list[dict[B]].push_back(dict[A]);
		}
		dfsCounter = 0;
		dfsNum.assign(N, -1);
		dfsLow.assign(N, 0);
		dfsParent.assign(N, -1);
		artV.assign(N, false);
		for (int i = 0; i < N; i++) {
			if (dfsNum[i] == -1) {
				dfsRoot = i;
				rootChildren = 0;
				artPoint(i);
				if (rootChildren > 1) artV[i] = true;
			}
		}
		ans = count(N);
		if (cas > 1) cout << "\n";
		cout << "City map #" << cas << ": " << ans << " camera(s) found\n";
		sort(vertices.begin(), vertices.end());
		for (int i = 0; i < ans; i++) {
			cout << vertices[i] << "\n";
		}
		cas++;
	}
	return 0;
}
