#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <queue>
using namespace std;

unordered_map<int, int> into;
unordered_map<int, vector<int>> adj_list;
unordered_map<int, bool> visited;
set<int> nodes;

int main() {
	int A, B, t=1;
	vector<int> empt;
	while(true) {
		cin >> A >> B;
		if (A < 0) break;
		bool isTree = true;
		int foundRoot = -1;
		into.clear();
		nodes.clear();
		adj_list.clear();
		into[B] = 1;
		nodes.insert(A);
		nodes.insert(B);
		if(A == B) isTree = false;
		if (A == B && A == 0) {
			cout << "Case " << t << " is a tree.\n";
			t++;
			continue;
		}
		adj_list[A] = empt;
		adj_list[B] = empt;
		adj_list[A].push_back(B);
		while(true) {
			cin >> A >> B;
			if (!(A||B)) break;
			if (A == B) isTree = false;
			if (into.find(B) == into.end()) into[B] = 1;
			else into[B]++;
			nodes.insert(A);
			nodes.insert(B);
			if (adj_list.find(A) == adj_list.end()) adj_list[A] = empt;
			if (adj_list.find(B) == adj_list.end()) adj_list[B] = empt;
			adj_list[A].push_back(B);
		}
		for (int cur: nodes) {
			if (into.find(cur) == into.end()) {
				if (foundRoot == -1) foundRoot = cur;
				else {
					isTree = false;
					break;
				}
			} else if (into[cur] != 1) {
				isTree = false;
				break;
			}
		}
		if (isTree && foundRoot != -1) {
			for (int cur: nodes) {
				visited[cur] = false;
			}
			visited[foundRoot] = true;
			queue<int> Q;
			Q.push(foundRoot);
			int found = 1;
			while(!Q.empty()) {
				int u = Q.front();
				Q.pop();
				for (int i = 0; i < (int) adj_list[u].size(); i++) {
					if (visited[adj_list[u][i]] == false) {
						visited[adj_list[u][i]] = true;
						Q.push(adj_list[u][i]);
						found++;
					}
				}
			}
			if (found == (int) nodes.size())
				cout << "Case " << t << " is a tree.\n";
			else cout << "Case " << t << " is not a tree.\n";
		}
		else cout << "Case " << t << " is not a tree.\n";
		t++;
	}
	return 0;
}
