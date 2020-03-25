#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

unordered_map<int, vector<int>> adj_list;
unordered_map<int, int> predec;
unordered_map<int, bool> visited;
vector<int> keys;

void reset() {
	for (int i = 0; i < keys.size(); i++) {
		visited[keys[i]] = false;
		predec[keys[i]] = -1;
	}
}

void BFS(int A, int B) {
	queue<int> Q;
	Q.push(A);
	predec[A] = A;
	visited[A] = true;
	while(!Q.empty()) {
		A = Q.front();
		Q.pop();
		if (A == B) break;
		for (int i = 0; i < adj_list[A].size(); i++) {
			if (visited[adj_list[A][i]] == false) {
				visited[adj_list[A][i]] = true;
				predec[adj_list[A][i]] = A;
				Q.push(adj_list[A][i]);
			}
		}
	}
	if (predec[B] == -1) {
		cout << "connection impossible\n";
		return;
	}
	int cur = B;
	vector<int> path;
	path.push_back(B);
	while(predec[cur] != cur) {
		cur = predec[cur];
		path.push_back(cur);
	}
	for (int i = path.size()-1; i > 0; i--) {
		cout << path[i] << " ";
	}
	cout << path[0] << "\n";
}

int main() {
	int N, id, Q, A, B;
	string line;
	stringstream ss;
	vector<int> empt;
	while(getline(cin, line)) {
		N = stoi(line);
		keys.clear();
		adj_list.clear();
		for (int n = 0; n < N; n++) {
			getline(cin, line);
			ss.str("");
			ss.clear();
			ss.str(line);
			ss >> id;
			keys.push_back(id);
			adj_list[id] = empt;
			ss.ignore();
			for (int i; ss >> i;) {
				adj_list[id].push_back(i);
				if (ss.peek() == ',') ss.ignore();
			}
		}
		getline(cin, line);
		Q = stoi(line);
		cout << "-----\n";
		for (int q = 0; q < Q; q++) {
			getline(cin, line);
			ss.str("");
			ss.clear();
			ss.str(line);
			ss >> A;
			ss >> B;
			reset();
			BFS(A, B);
		}
	}
	return 0;
}
