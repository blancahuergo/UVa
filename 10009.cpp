#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

unordered_map<char, int> dict;
unordered_map<int, char> dict_inv;
vector<vector<int>> adj_list;

void BFS(int S, int D, int N) {
	queue<int> Q;
	vector<bool> visited;
	visited.assign(N, false);
	vector<int> predec;
	predec.assign(N, -1);
	Q.push(S);
	predec[S] = S;
	visited[S] = true;
	while(!Q.empty()) {
		S = Q.front();
		Q.pop();
		if (S == D) break;
		for (int i = 0; i < adj_list[S].size(); i++) {
			if (!visited[adj_list[S][i]]) {
				visited[adj_list[S][i]] = true;
				Q.push(adj_list[S][i]);
				predec[adj_list[S][i]] = S;
			}
		}
	}
	int cur = D;
	string ret = "";
	ret += dict_inv[D];
	while(predec[cur] != cur) {
		cur = predec[cur];
		ret += dict_inv[cur];
	}
	for (int i = ret.length()-1; i >= 0; i--) {
		cout << ret[i];
	}
	cout << "\n";
}

int main() {
	int T, N, M, Q, c;
	string A, B;
	vector<int> empt;
	cin >> T;
	while(T--) {
		cin >> M >> Q;
		c = 0;
		dict.clear();
		dict_inv.clear();
		adj_list.clear();
		while(M--) {
			cin >> A >> B;
			if (dict.find(A[0]) == dict.end()) {
				dict[A[0]] = c;
				dict_inv[c] = A[0];
				adj_list.push_back(empt);
				c++;
			}
			if (dict.find(B[0]) == dict.end()) {
				dict[B[0]] = c;
				dict_inv[c] = B[0];
				adj_list.push_back(empt);
				c++;
			}
			adj_list[dict[A[0]]].push_back(dict[B[0]]);
			adj_list[dict[B[0]]].push_back(dict[A[0]]);
		}
		N = c;
		while(Q--) {
			cin >> A >> B;
			BFS(dict[A[0]], dict[B[0]], N);
		}
		if (T) cout << "\n";
	}
	return 0;
}
