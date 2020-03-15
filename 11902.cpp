#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj_list;
vector<bool> visited;
vector<bool> reachable;

void missingDFS(int miss, int u) {
	if (u == miss) return;
	visited[u] = true;
	for (int j = 0; j < adj_list[u].size(); j++) {
		if (!visited[adj_list[u][j]])
			missingDFS(miss, adj_list[u][j]);
	}
}

int main() {
	int T, N, cur;
	vector<int> empt;
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		cin >> N;
		adj_list.assign(N, empt);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> cur;
				if (cur) adj_list[i].push_back(j);
			}
		}
		cout << "Case " << cas << ":\n+";
		for (int i = 0; i < 2*N-1; i++) cout << "-";
		cout << "+\n";
		visited.assign(N, false);
		missingDFS(-1, 0);
		reachable = visited;
		for (int i = 0; i < N; i++) {
			cout << "|";
			if (visited[i]) cout << "Y";
			else cout << "N";
		}
		cout << "|\n";
		cout << "+";
		for (int i = 0; i < 2*N-1; i++) cout << "-";
		cout << "+\n";
		for (int i = 1; i < N; i++) {
			if (!reachable[i]) {
				for (int i = 0; i < N; i++) {
					cout << "|";
					cout << "N";
				}
				cout << "|\n";
			} else {
				visited.assign(N, false);
				missingDFS(i, 0);
				for (int i = 0; i < N; i++) {
					cout << "|";
					if ((!visited[i]) && reachable[i]) cout << "Y";
					else cout << "N";
				}
				cout << "|\n";
			}
			cout << "+";
			for (int i = 0; i < 2*N-1; i++) cout << "-";
			cout << "+\n";
		}
	}
	return 0;
}
