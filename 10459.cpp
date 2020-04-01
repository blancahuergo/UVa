#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

vector<int> dist, curPath;
vector<bool> visited;
vector<vector<int>> adj_list;
set<int> best, worst;
int maxDist;

void DFS(int u, int pathLen, int st) {
	curPath.push_back(u);
	visited[u] = true;
	if (pathLen > maxDist) {
		maxDist = pathLen;
		best.clear();
		worst.clear();
	}
	if (pathLen == maxDist) {
		worst.insert(u);
		worst.insert(st);
		if (pathLen % 2 == 0) {
			best.insert(curPath[pathLen/2]);
		} else {
			best.insert(curPath[pathLen/2]);
			best.insert(curPath[pathLen/2 + 1]);
		}
	}
	for (int i = 0; i < (int) adj_list[u].size(); i++) {
		int v = adj_list[u][i];
		if (!visited[v]) {
			DFS(v, pathLen+1, st);
		}
	}
	curPath.pop_back();
	visited[u] = false;
}

int main() {
	int N, K, u, pos;
	vector<int> empt;
	while(cin >> N) {
		adj_list.assign(N, empt);
		for (int n = 0; n < N; n++) {
			cin >> K;
			while(K--) {
				cin >> u;
				adj_list[n].push_back(u-1);
			}
		}
		dist.assign(N, 1000000);
		dist[0] = 0;
		queue<int> Q;
		Q.push(0);
		maxDist = 0;
		while(!Q.empty()) {
			u = Q.front();
			Q.pop();
			if (dist[u] > maxDist) {
				pos = u;
				maxDist = dist[u];
			}
			for (int i = 0; i < (int) adj_list[u].size(); i++) {
				int v = adj_list[u][i];
				if (dist[v] == 1000000) {
					dist[v] = dist[u]+1;
					Q.push(v);
				}
			}
		}
		best.clear();
		worst.clear();
		curPath.clear();
		visited.assign(N, false);
		DFS(pos, 0, pos);
		visited.assign(N, false);
		curPath.clear();
		for (int cur: worst) {
			if (cur != pos) {
				pos = cur;
				break;
			}
		}
		DFS(pos, 0, pos);
		cout << "Best Roots  :";
		for (int cur : best) {
			cout << " " << (cur+1);
		}
		cout << "\nWorst Roots :";
		for (int cur : worst) {
			cout << " " << (cur+1);
		}
		cout << "\n";
	}
	return 0;
}
