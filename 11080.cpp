#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite;
int ones, zeros;
vector<int> colour;
vector<vector<int>> adj_list;

void BFS(int S) {
	int u, v;
	queue<int> Q;
	Q.push(S);
	while(!Q.empty()) {
		u = Q.front();
		Q.pop();
		if (colour[u] == 1) ones++;
		else zeros++;
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
	vector<int> empt;
	vector<int> ans;
	int T, N, M, a, b, count;
	cin >> T;
	while(T--) {
		cin >> N >> M;
		adj_list.assign(N, empt);
		if (M == 0) {
			ans.push_back(N);
			continue;
		}
		while(M--) {
			cin >> a >> b;
			adj_list[a].push_back(b);
			adj_list[b].push_back(a);
		}
		isBipartite = true;
		colour.assign(N, -1);
		count = 0;
		for (int i = 0; i < N; i++) {
			if (colour[i] == -1) {
				colour[i] = 1;
				ones = 0;
				zeros = 0;
				BFS(i);
				if (zeros > 0)
					count += min(ones, zeros);
				else count += ones;
			}
			if (!isBipartite) break;
		}
		if (isBipartite) ans.push_back(count);
		else ans.push_back(-1);
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	return 0;
}
