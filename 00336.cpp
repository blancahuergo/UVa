#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

unordered_map<int, vector<int>> adj_list;
unordered_map<int, bool> visited;
unordered_map<int, int> dist;

int BFS(int S, int TTL) {
	int u, count = 0;
	queue<int> Q;
	Q.push(S);
	dist[S] = 0;
	visited[S] = true;
	while(!Q.empty()) {
		u = Q.front();
		Q.pop();
		for (int i = 0; i < adj_list[u].size(); i++) {
			if (!visited[adj_list[u][i]]) {
				visited[adj_list[u][i]] = true;
				dist[adj_list[u][i]] = dist[u]+1;
				if (dist[adj_list[u][i]] > TTL) count++;
				Q.push(adj_list[u][i]);
			}
		}
	}
	return count;
}

int main() {
	int t = 1, M, A, B, S, TTL, ans, N;
	vector<int> empt, keys;
	unordered_map<int, vector<int>>::iterator it;
	while(true) {
		cin >> M;
		if (!M) break;
		adj_list.clear();
		visited.clear();
		keys.clear();
		N = 0;
		for (int m = 0; m < M; m++) {
			cin >> A >> B;
			if (adj_list.find(A) == adj_list.end()) {
				adj_list[A] = empt;
				visited[A] = false;
				keys.push_back(A);
				N++;
			}
			if (adj_list.find(B) == adj_list.end()) {
				adj_list[B] = empt;
				visited[B] = false;
				keys.push_back(B);
				N++;
			}
			adj_list[A].push_back(B);
			adj_list[B].push_back(A);
		}
		while(true) {
			cin >> S >> TTL;
			if (!(S || TTL)) break;
			for (int i = 0; i < keys.size(); i++) {
				visited[keys[i]] = false;
			}
			dist.clear();
			ans = BFS(S, TTL);
			for (it = adj_list.begin(); it != adj_list.end(); it++) {
				if (!visited[it->first]) {
					ans += BFS(it->first, -100);
					ans++;
				}
			}
			cout << "Case " << t << ": " << ans << " nodes not reachable from node " << S << " with TTL = " << TTL << ".\n";
			t++;
		}
	}
	return 0;
}
