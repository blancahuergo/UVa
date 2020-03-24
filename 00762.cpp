#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

unordered_map<string, int> dict;
unordered_map<int, string> dict_inv;
vector<vector<int>> adj_list;

void BFS(string A, string B, int N) {
	if (dict.find(A) == dict.end() || dict.find(B) == dict.end()) {
		cout << "No route\n";
		return;
	}
	int S = dict[A];
	int D = dict[B];
	vector<int> dist, predec;
	dist.assign(N, -1);
	predec.assign(N, -1);
	queue<int> Q;
	Q.push(S);
	dist[S] = 0;
	predec[S] = S;
	while(!Q.empty()) {
		S = Q.front();
		Q.pop();
		if (S == D) break;
		for (int i = 0; i < adj_list[S].size(); i++) {
			if (dist[adj_list[S][i]] == -1) {
				dist[adj_list[S][i]] = dist[S]+1;
				predec[adj_list[S][i]] = S;
				Q.push(adj_list[S][i]);
			}
		}
	}
	if (dist[D] == -1) {
		cout << "No route\n";
		return;
	} else {
		int cur = D;
		vector<pair<int, int>> edges;
		while(predec[cur] != cur) {
			edges.push_back({predec[cur], cur});
			cur = predec[cur];
		}
		for (int i = edges.size() - 1; i >= 0; i--) {
			cout << dict_inv[edges[i].first] << " " << dict_inv[edges[i].second] << "\n";
		}
	}
}

int main() {
	int M, N, c;
	vector<int> empt;
	string A, B, S, D;
	bool print_line = false;
	while(cin >> M) {
		c = 0;
		adj_list.clear();
		dict.clear();
		dict_inv.clear();
		while(M--) {
			cin >> A >> B;
			if (dict.find(A) == dict.end()) {
				dict[A] = c;
				dict_inv[c] = A;
				adj_list.push_back(empt);
				c++;
			}
			if (dict.find(B) == dict.end()) {
				dict[B] = c;
				dict_inv[c] = B;
				adj_list.push_back(empt);
				c++;
			}
			adj_list[dict[A]].push_back(dict[B]);
			adj_list[dict[B]].push_back(dict[A]);
		}
		N = c;
		cin >> S >> D;
		if (print_line) cout << "\n";
		BFS(S, D, N);
		print_line = true;
	}
	return 0;
}
