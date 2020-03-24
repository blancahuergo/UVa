#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj_list;

void BFS(int S, int D, int N) {
	int init_S = S;
	vector<int> dist;
	dist.assign(N, -1);
	dist[S] = 0;
	queue<int> Q;
	Q.push(S);
	while(!Q.empty()) {
		S = Q.front();
		Q.pop();
		for (int i = 0; i < adj_list[S].size(); i++) {
			if (dist[adj_list[S][i]] == -1) {
				dist[adj_list[S][i]] = dist[S]+1;
				Q.push(adj_list[S][i]);
			}
		}
	}
	cout << init_S << " " << D << " " << dist[D]-1 << "\n";
}

int main() {
	int T, N, init, num, other, S, D;
	vector<int> empt;
	cin >> T;
	while(T--) {
		cin >> N;
		adj_list.assign(N, empt);
		for (int n = 0; n < N; n++) {
			cin >> init >> num;
			while(num--) {
				cin >> other;
				adj_list[init].push_back(other);
				adj_list[other].push_back(init);
			}
		}
		cin >> S >> D;
		BFS(S, D, N);
		if (T) cout << "\n";
	}
	return 0;
}
