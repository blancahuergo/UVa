#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj_list;
vector<int> freq;

int BFS(int S, int N) {
	vector<int> dist;
	dist.assign(N, -1);
	dist[S] = 0;
	queue<int> Q;
	Q.push(S);
	while(!Q.empty()) {
		S = Q.front();
		Q.pop();
		for (int i = 0; i < adj_list[S].size(); i++) {
			if (dist[adj_list[S][i]] == -1) {
				dist[adj_list[S][i]] = dist[S]+1;
				Q.push(adj_list[S][i]);
			}
		}
	}
	int tot = 0;
	for (int i = 0; i < N; i++) {
		if (freq[i] >= 2)
			tot += dist[i];
	}
	return tot;
}

int main() {
	int T, N, S, k, cur, res, stat;
	cin >> T;
	vector<int> curLine, empt;
	while(T--) {
		cin >> N >> S;
		adj_list.assign(N, empt);
		freq.assign(N, 0);
		while(S--) {
			curLine.clear();
			while(true) {
				cin >> k;
				if (!k) break;
				curLine.push_back(k);
			}
			for (int i = 0; i < curLine.size()-1; i++) {
				freq[curLine[i]-1]++;
				adj_list[curLine[i]-1].push_back(curLine[i+1]-1);
				adj_list[curLine[i+1]-1].push_back(curLine[i]-1);
			}
			freq[curLine[curLine.size()-1]-1]++;
		}
		res = 2000000000;
		for (int i = 0; i < N; i++) {
			if (freq[i] >= 2) {
				cur = BFS(i, N);
				if (cur < res) {
					res = cur;
					stat = i+1;
				}
			}
		}
		cout << "Krochanska is in: " << stat << "\n";
	}
	return 0;
}
