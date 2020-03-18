#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite;
int total, ones, zeros;
vector<int> colour;
vector<vector<int>> adj_list;

void BFS(int S) {
	int u, v;
	queue<int> Q;
	Q.push(S);
	while(!Q.empty()) {
		u = Q.front();
		if (colour[u]) ones++;
		else zeros++;
		Q.pop();
		for (int k = 0; k < adj_list[u].size(); k++) {
			v = adj_list[u][k];
			if (colour[v] == -1) {
				colour[v] = 1-colour[u];
				Q.push(v);
			} else if (colour[v] == colour[u]) {
				isBipartite = false;
			}
		}
	}
}

int main() {
	int T, N, n, j;
	vector<int> empt;
	vector<int> ans;
	cin >> T;
	while(T--) {
		cin >> N;
		if (N <= 0) {
			cout << "0\n";
			continue;
		}
		adj_list.assign(N, empt);
		colour.assign(N, -1);
		for (int k = 0; k < N; k++) {
			cin >> n;
			while(n--) {
				cin >> j;
				if (j < 1 || j > N) continue;
				adj_list[k].push_back(j-1);
				adj_list[j-1].push_back(k);
			}
		}
		total = 0;
		for (int i = 0; i < N; i++) {
			isBipartite = true;
			if (colour[i] == -1) {
				colour[i] = 1;
				ones = 0;
				zeros = 0;
				BFS(i);
				if (isBipartite) total += max(ones, zeros);
			}
		}
		ans.push_back(total);
	}
	for (int y = 0; y < ans.size(); y++) {
		cout << ans[y] << endl;
	}
	return 0;
}
