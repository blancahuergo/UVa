#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<vector<int>>> adj_list;
vector<vector<pair<int, int>>> cost;
vector<bool> visited;
vector<int> predec;
unordered_map<string, int> dict;

pair<int, int> simplify(int a, int b) {
	int div = 2, mn = min(a, b), mx = max(a, b);
	while(div <= mn) {
		if (mn % div == 0 && mx % div == 0) {
			mn /= div;
			mx /= div;
		} else div++;
	}
	if (a > b) return make_pair(mx, mn);
	else return make_pair(mn, mx);
}

void DFS(int u) {
	visited[u] = true;
	int v;
	for (int j = 0; j < adj_list[u].size(); j++) {
		v = adj_list[u][j][0];
		if (!visited[v]) {
			predec[v] = u;
			DFS(v);
		}
	}
}

pair<int, int> traverse(int A, int B) {
	int cur = predec[B];
	pair<int, int> ret = cost[predec[B]][B], next_p;
	//cout << predec[B] << " " << ret.first << " " << B << " " << ret.second << endl;
	while(cur != A) {
		next_p = cost[predec[cur]][cur];
		ret = make_pair(ret.first*next_p.first, ret.second*next_p.second);
		ret = simplify(ret.first, ret.second);
		//cout << predec[cur] << " " << ret.first << " " << cur << " " << ret.second << endl;
		cur = predec[cur];
	}
	return simplify(ret.first, ret.second);
}

int main() {
	string com, itemA, itemB;
	vector<vector<int>> empt;
	pair<int, int> cur;
	adj_list.assign(60, empt);
	vector<pair<int, int>> empt2;
	empt2.assign(60, make_pair(0, 0));
	cost.assign(60, empt2);
	int q_A, q_B, count = 0;
	while(true) {
		cin >> com;
		if (com[0] == '.') break;
		if (com[0] == '!') {
			cin >> q_A >> itemA >> com >> q_B >> itemB;
			if (dict.find(itemA) == dict.end()) {
				dict[itemA] = count;
				count++;
			}
			if (dict.find(itemB) == dict.end()) {
				dict[itemB] = count;
				count++;
			}
			cur = simplify(q_A, q_B);
			adj_list[dict[itemA]].push_back({dict[itemB], cur.first, cur.second});
			adj_list[dict[itemB]].push_back({dict[itemA], cur.second, cur.first});
			cost[dict[itemA]][dict[itemB]] = cur;
			cost[dict[itemB]][dict[itemA]] = make_pair(cur.second, cur.first);
		} else {
			cin >> itemA >> com >> itemB;
			visited.assign(count, false);
			predec.assign(count, 0);
			DFS(dict[itemA]);
			if (visited[dict[itemB]]) {
				cur = traverse(dict[itemA], dict[itemB]);
				cout << cur.first << " " << itemA << " = " << cur.second << " " << itemB << endl;
			} else {
				cout << "? " << itemA << " = ? " << itemB << "\n";
			}
		}
	}
	return 0;
}
