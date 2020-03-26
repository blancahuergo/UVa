#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <queue>
using namespace std;

vector<string> dict;
vector<vector<int>> adj_list;
unordered_map<string, int> mapping;

int dist(int i, int j) {
	if (dict[i].length() != dict[j].length()) return -1;
	int tot = 0;
	for (int k = 0; k < dict[i].length(); k++)
		if (dict[i][k] != dict[j][k]) tot++;
	return tot;
}

void buildList() {
	int N = (int) dict.size();
	vector<int> empt;
	adj_list.assign(N, empt);
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			if (dist(i, j) == 1) {
				adj_list[i].push_back(j);
				adj_list[j].push_back(i);
			}
		}
	}
}

void BFS(int S, int D) {
	int N = (int) dict.size();
	vector<int> dist, predec;
	dist.assign(N, -1);
	predec.assign(N, -1);
	queue<int> Q;
	Q.push(S);
	dist[S] = 0;
	predec[S] = S;
	int W;
	while(!Q.empty()) {
		W = Q.front();
		Q.pop();
		for (int i = 0; i < adj_list[W].size(); i++) {
			if (dist[adj_list[W][i]] == -1) {
				Q.push(adj_list[W][i]);
				dist[adj_list[W][i]] = dist[W]+1;
				predec[adj_list[W][i]] = W;
			}
		}
	}
	if (dist[D] == -1) {
		cout << "No solution.\n";
		return;
	}
	vector<string> ans;
	W = D;
	while(W != S) {
		ans.push_back(dict[W]);
		W = predec[W];
	}
	cout << dict[S] << "\n";
	for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << "\n";
}

int main() {
	string word, line, A, B;
	int c = 0;
	stringstream ss;
	bool print_line = false;
	while(true) {
		getline(cin, word);
		if (word.size() == 0 || !(word[0] >= 'a' && word[0] <= 'z')) break;
		ss.str("");
		ss.clear();
		ss.str(word);
		ss >> word;
		dict.push_back(word);
		mapping[word] = c;
		c++;
	}
	buildList();
	// get queries
	while(getline(cin, line)) {
		ss.str("");
		ss.clear();
		ss.str(line);
		ss >> A;
		ss >> B;
		if (print_line) cout << "\n";
		BFS(mapping[A], mapping[B]);
		print_line = true;
	}
	return 0;
}
