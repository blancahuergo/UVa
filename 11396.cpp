#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite;
vector<int> colour;
vector<vector<int>> adj_list;

void BFS(int S) {
	int u, v;
	queue<int> Q;
	Q.push(S);
	while(!Q.empty()) {
		u = Q.front();
		Q.pop();
		for (int k = 0; k < adj_list[u].size(); k++) {
			v = adj_list[u][k];
			if (colour[v] == -1) {
				colour[v] = 1-colour[u];
				Q.push(v);
			} else if (colour[v] == colour[u]) {
				isBipartite = false;
				return;
			}
		}
	}
}

int main() {
	int V, a, b;
	vector<int> empt;
	while(true) {
		cin >> V;
		if (!V) break;
		adj_list.assign(V, empt);
		while(true) {
			cin >> a >> b;
			if (!(a || b)) break;
			adj_list[a-1].push_back(b-1);
			adj_list[b-1].push_back(a-1);
		}
		colour.assign(V, -1);
		isBipartite = true;
		for (int i = 0; i < V; i++) {
			if (colour[i] == -1) {
				colour[i] = 1;
				BFS(i);
			}
			if (!isBipartite) break;
		}
		if (isBipartite) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
