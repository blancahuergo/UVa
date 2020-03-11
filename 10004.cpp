#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, l, a, b, j, S;
	vector<vector<int>> adj_list;
	vector<int> empt;
	vector<int> colour;
	vector<bool> visited;
	bool possible;
	while(true) {
		cin >> n;
		possible = true;
		adj_list.assign(n, empt);
		if (!n) break;
		cin >> l;
		for (int i = 0; i < l; i++) {
			cin >> a >> b;
			adj_list[a].push_back(b);
			adj_list[b].push_back(a);
		}
		colour.assign(n, -1);
		colour[0] = 1;
		queue<int> indices;
		indices.push(0);
		visited.assign(n, false);
		while((!indices.empty()) && possible) {
			S = indices.front();
			indices.pop();
			if (visited[S]) continue;
			visited[S] = true;
			for (int i = 0; i < adj_list[S].size(); i++) {
				j = adj_list[S][i];
				if (colour[j] == colour[S]) {
					possible = false;
					break;
				} else if (colour[j] == -1) {
					colour[j] = 1-colour[S];
				}
				indices.push(j);
			}
		}
		if (possible) cout << "BICOLORABLE.\n";
		else cout << "NOT BICOLORABLE.\n";
	}
	return 0;
}
