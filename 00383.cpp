#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

unordered_map<string, int> dict;
vector<vector<int>> adj_list;

int BFS(int S, int D, int N) {
	vector<bool> visited;
	vector<int> dist;
	visited.assign(N, false);
	dist.assign(N, -1);
	dist[S] = 0;
	visited[S] = true;
	queue<int> Q;
	Q.push(S);
	while(!Q.empty()) {
		S = Q.front();
		if (S == D) break;
		Q.pop();
		for (int i = 0; i < adj_list[S].size(); i++) {
			if (!visited[adj_list[S][i]]) {
				visited[adj_list[S][i]] = true;
				Q.push(adj_list[S][i]);
				dist[adj_list[S][i]] = dist[S]+1;
			}
		}
	}
	return dist[D];
}

int main() {
	int T, N, M, Q, sz, ans;
	vector<int> empt;
	string nam, A, B;
	cin >> T;
	cout << "SHIPPING ROUTES OUTPUT\n\n";
	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> Q;
		dict.clear();
		adj_list.assign(N, empt);
		for (int n = 0; n < N; n++) {
			cin >> nam;
			dict[nam] = n;
		}
		while(M--) {
			cin >> A >> B;
			adj_list[dict[A]].push_back(dict[B]);
			adj_list[dict[B]].push_back(dict[A]);
		}
		cout << "DATA SET  " << t << "\n\n";
		while(Q--) {
			cin >> sz >> A >> B;
			ans = BFS(dict[A], dict[B], N);
			if (ans == -1) cout << "NO SHIPMENT POSSIBLE\n";
			else cout << "$" << sz*100*ans << "\n";
		}
		cout << "\n";
	}
	cout << "END OF OUTPUT\n";
	return 0;
}
