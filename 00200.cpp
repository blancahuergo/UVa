#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj_list;
vector<int> TS;
vector<bool> visited;
vector<bool> found_let;

void find_edges(string line, string last) {
	int ind = 0, max_ind = min(line.size(), last.size());
	while(line[ind] == last[ind]) {
		found_let[line[ind] - 'A'] = true;
		ind++;
		if (ind == max_ind) break;
	}
	if (ind == max_ind) return;
	adj_list[last[ind] - 'A'].push_back(line[ind] - 'A');
	for (int i = ind; i < line.size(); i++)
		found_let[line[i] - 'A'] = true;
	for (int i = ind; i < last.size(); i++)
		found_let[last[i] - 'A'] = true;
}

void DFS(int u) {
	visited[u] = true;
	for (int i = 0; i < adj_list[u].size(); i++) {
		if (!visited[adj_list[u][i]])
			DFS(adj_list[u][i]);
	}
	TS.push_back(u);
}

int main() {
	vector<int> empt;
	adj_list.assign(26, empt);
	string line, last;
	cin >> last;
	found_let.assign(26, false);
	while(true) {
		cin >> line;
		if (line[0] == '#') break;
		find_edges(line, last);
		last = line;
	}
	// run toposort on adj_list
	visited.assign(26, false);
	TS.clear();
	for (int i = 0; i < 26; i++) {
		if (!found_let[i]) continue;
		if (!visited[i])
			DFS(i);
	}
	for (int i = TS.size()-1; i >= 0; i--)
		cout << ((char) ('A' + TS[i]));
	cout << "\n";
	return 0;
}
