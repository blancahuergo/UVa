#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<int> inDeg;
vector<bool> used;
vector<vector<int>> adj_list;
unordered_map<string, int> dict;
unordered_map<int, string> dict_inv;
vector<string> result;

int main() {
	string line, name, orig;
	stringstream ss;
	vector<int> empt;
	int c, S, ret;
	while(true) {
		getline(cin, line);
		M = stoi(line);
		if (!M) break;
		adj_list.clear();
		dict.clear();
		dict_inv.clear();
		inDeg.clear();
		c = 0;
		while(M--) {
			getline(cin, line);
			ss.str("");
			ss.clear();
			ss.str(line);
			ss >> orig;
			if (dict.find(orig) == dict.end()) {
				dict[orig] = c;
				dict_inv[c] = orig;
				adj_list.push_back(empt);
				inDeg.push_back(0);
				c++;
			}
			while(ss >> name) {
				if (dict.find(name) == dict.end()) {
					dict[name] = c;
					dict_inv[c] = name;
					adj_list.push_back(empt);
					inDeg.push_back(0);
					c++;
				}
				adj_list[dict[orig]].push_back(dict[name]);
				inDeg[dict[name]]++;
			}
		}
		N = c;
		queue<int> Q;
		for (int i = 0; i < N; i++) {
			if (inDeg[i] == 0) Q.push(i);
		}
		ret = N;
		used.assign(N, false);
		while(!Q.empty()) {
			S = Q.front();
			Q.pop();
			used[S] = true;
			ret--;
			for (int j = 0; j < adj_list[S].size(); j++) {
				inDeg[adj_list[S][j]]--;
				if (inDeg[adj_list[S][j]] == 0) Q.push(adj_list[S][j]);
			}
		}
		cout << ret << endl;
		result.clear();
		for (int i = 0; i < N; i++) {
			if (!used[i]) result.push_back(dict_inv[i]);
		}
		sort(result.begin(), result.end());
		cout << result[0];
		for (int i = 1; i < result.size(); i++)
			cout << " " << result[i];
		cout << "\n";
	}
	return 0;
}
