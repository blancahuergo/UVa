#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj_list;
vector<bool> visited;
vector<int> TS;

void DFS(int u) {
	visited[u] = true;
	for (int i = 0; i < adj_list[u].size(); i++) {
		if (!visited[adj_list[u][i]])
			DFS(adj_list[u][i]);
	}
	TS.push_back(u+1);
}

int main() {
	int n, m, i, j;
	vector<int> empt;
	while(true) {
		cin >> n >> m;
		if (!(n||m)) break;
		adj_list.assign(n, empt);
		for (int k = 0; k < m; k++) {
			cin >> i >> j;
			adj_list[i-1].push_back(j-1);
		}
		visited.assign(n, false);
		TS.clear();
		for (int s = 0; s < n; s++) {
			if (!visited[s])
				DFS(s);
		}
		for (int k = TS.size()-1; k > 0; k--)
			cout << TS[k] << " ";
		cout << TS[0] << endl;
	}
	return 0;
}
