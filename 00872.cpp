#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int N;
unordered_map<char, int> dict;
unordered_map<int, char> dict_inv;
vector<vector<int>> adj_list;
vector<bool> visited;
vector<int> into_v;
vector<int> path;
vector<string> perms;

void addPath() {
	string ret = "";
	ret += dict_inv[path[0]];
	for (int i = 1; i < N; i++) {
		ret += ' ';
		ret += dict_inv[path[i]];
	}
	perms.push_back(ret);
}

void findTopoOrders() {
	int u;
	for (int v = 0; v < N; v++) {
		if (into_v[v] == 0 && (!visited[v])) {
			for (int i = 0; i < adj_list[v].size(); i++) {
				u = adj_list[v][i];
				into_v[u]--;
			}
			path.push_back(v);
			visited[v] = true;
			findTopoOrders();
			for (int i = 0; i < adj_list[v].size(); i++) {
				u = adj_list[v][i];
				into_v[u]++;
			}
			path.pop_back();
			visited[v] = false;
		}
	}
	if (path.size() == N) {
		addPath();
	}
}

int main() {
	int T;
	bool first = true;
	vector<int> empt;
	string line;
	getline(cin, line);
	T = stoi(line);
	while(T--) {
		getline(cin, line);
		getline(cin, line);
		N = 0;
		for (int i = 0; i < line.length(); i+=2) {
			dict[line[i]] = N;
			dict_inv[N] = line[i];
			N++;
		}
		adj_list.assign(N, empt);
		into_v.assign(N, 0);
		getline(cin, line);
		for (int i = 0; i < line.length()-2; i+=4) {
			adj_list[dict[line[i]]].push_back(dict[line[i+2]]);
			into_v[dict[line[i+2]]]++;
		}
		path.clear();
		perms.clear();
		visited.assign(N, false);
		findTopoOrders();
		if (!first) cout << "\n";
		first = false;
		if (perms.size() == 0) {
			cout << "NO\n";
			continue;
		}
		sort(perms.begin(), perms.end());
		for (int i = 0; i < perms.size(); i++) {
			cout << perms[i] << endl;
		}
	}
	return 0;
}
