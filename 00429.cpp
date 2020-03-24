#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<vector<int>> adj_list;

int DIST(string A, string B) {
	if (A.length() != B.length()) return -1;
	int ans = 0;
	for (int i = 0; i < A.length(); i++) ans += A[i] != B[i];
	return ans;
}

int BFS(int S, int D, int N) {
	vector<int> dist;
	dist.assign(N, -1);
	vector<bool> visited;
	visited.assign(N, false);
	queue<int> Q;
	Q.push(S);
	dist[S] = 0;
	visited[S] = true;
	while(!Q.empty()) {
		S = Q.front();
		Q.pop();
		for (int i = 0; i < adj_list[S].size(); i++) {
			if (!visited[adj_list[S][i]]) {
				visited[adj_list[S][i]] = true;
				dist[adj_list[S][i]] = dist[S]+1;
				visited[adj_list[S][i]] = true;
				Q.push(adj_list[S][i]);
			}
		}
	}
	return dist[D];
}

int main() {
	int T, N, ds, c, ans;
	vector<string> words;
	unordered_map<string, int> dict;
	string line, word, S, D;
	stringstream ss;
	vector<int> empt;
	getline(cin, line);
	T = stoi(line);
	getline(cin, line);
	while(T--) {
		c = 0;
		words.clear();
		dict.clear();
		while(true) {
			getline(cin, line);
			if (line[0] == '*') break;
			ss.str("");
			ss.clear();
			ss.str(line);
			ss >> word;
			words.push_back(word);
			dict[word] = c;
			c++;
		}
		N = (int) words.size();
		adj_list.assign(N, empt);
		for (int i = 0; i < N; i++) {
			for (int j = i+1; j < N; j++) {
				ds = DIST(words[i], words[j]);
				if (ds == 1) {
					adj_list[i].push_back(j);
					adj_list[j].push_back(i);
				}
			}
		}
		while(getline(cin, line)) {
			if (!(line[0] >= 'a' && line[0] <= 'z')) break;
			ss.str("");
			ss.clear();
			ss.str(line);
			ss >> S;
			ss >> D;
			ans = BFS(dict[S], dict[D], N);
			cout << S << " " << D << " " << ans << "\n";
		}
		if (T) cout << "\n";
	}
	return 0;
}
