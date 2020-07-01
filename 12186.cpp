#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;
vector<int> req;

int minimum(int u) {
	if(adj[u].size() == 0) return 1;
	int v, val;
	priority_queue<pair<int, int>> PQ;
	for (int i = 0; i < (int) adj[u].size(); i++) {
		v = adj[u][i];
		val = minimum(v);
		PQ.push({-val, v});
	}
	int res = 0;
	pair<int, int> p;
	for (int i = 0; i < req[u]; i++) {
		p = PQ.top();
		PQ.pop();
		res -= p.first;
	}
	return res;
}

int main() {
	int N, T, boss;
	while(true) {
		cin >> N >> T;
		if (!(N||T)) break;
		adj.assign(N+1, vector<int>());
		req.assign(N+1, 0);
		for(int i = 0; i < N; i++) {
			cin >> boss;
			adj[boss].push_back(i+1);
		}
		for (int i = 0; i <= N; i++) req[i] = (T*adj[i].size()-1)/100 + 1;
		cout << minimum(0) << "\n";
	}
	return 0;
}
