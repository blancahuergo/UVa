#include <iostream>
#include <stdio.h>
#include <vector>
#include <sstream>
using namespace std;

int root(int a, vector<int> &parent) {
	int last_a;
	while(a != parent[a]) {
		last_a = a;
		a = parent[a];
		parent[last_a] = parent[a];
	}
	return a;
}

bool isSameSet(int a, int b, vector<int> &parent) {
	return root(a, parent) == root(b, parent);
}

void merge(int a, int b, vector<int> &parent, vector<int> &rank) {
	int r_a, r_b;
	r_a = root(a, parent);
	r_b = root(b, parent);
	if (r_a == r_b) return;
	if (rank[r_a] > rank[r_b]) {
		parent[r_b] = r_a;
	} else if (rank[r_b] > rank[r_a]) {
		parent[r_a] = r_b;
	} else {
		parent[r_a] = r_b;
		rank[r_b]++;
	}
}

int main() {
	int cases, N, A, B, suc, unsuc;
	char com;
	string line;
	vector<int> parent;
	vector<int> rank;
	cin >> cases;
	for (int cas = 0; cas < cases; cas++) {
		cin >> N;
		getline(cin, line);
		parent.clear();
		rank.clear();
		parent.assign(N, 0);
		for (int u = 0; u < N; u++) parent[u] = u;
		rank.assign(N, 0);
		suc = 0;
		unsuc = 0;
		while(getline(cin, line), line.length() > 2) {
			stringstream ss(line);
			ss >> com >> A >> B;
			if (com == 'c') {
				merge(A-1, B-1, parent, rank);
			} else {
				if (isSameSet(A-1, B-1, parent)) {
					suc++;
				} else {
					unsuc++;
				}
			}
		}
		if (cas) cout << "\n";
		cout << suc << "," << unsuc << endl;
	}
	return 0;
}
