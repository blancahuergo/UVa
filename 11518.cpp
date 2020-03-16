#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj_list;
vector<bool> visited;
int tot_vis;

void DFS(int u) {
	if (visited[u]) return;
	visited[u] = true;
	tot_vis++;
	for (int j = 0; j < adj_list[u].size(); j++) {
		if (!visited[adj_list[u][j]])
			DFS(adj_list[u][j]);
	}
}

int main() {
	int T, n, m, l, x, y, z;
	vector<int> empt;
	cin >> T;
	while(T--) {
		cin >> n >> m >> l;
		adj_list.assign(n, empt);
		for (int i = 0; i < m; i++) {
			cin >> x >> y;
			adj_list[x-1].push_back(y-1);
		}
		tot_vis = 0;
		visited.assign(n, false);
		for (int i = 0; i < l; i++) {
			cin >> z;
			DFS(z-1);
		}
		cout << tot_vis << endl;
	}
	return 0;
}
