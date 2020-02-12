#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> parent;
vector<int> rnk;
vector<unordered_set<int>> trees;
int numSets;

int root(int a) {
	int last_a;
	while(a != parent[a]) {
		last_a = a;
		a = parent[a];
		parent[last_a] = parent[a];
	}
	return a;
}

void mergeByRank(int a, int b) {
	int r_a, r_b;
	r_a = root(a);
	r_b = root(b);
	if (r_a == r_b) return;
	numSets--;
	if (rnk[r_a] > rnk[r_b]) {
		parent[r_b] = r_a;
	} else if (rnk[r_b] > rnk[r_a]) {
		parent[r_a] = r_b;
	} else {
		parent[r_a] = r_b;
		rnk[r_b]++;
	}
}

void findMerge(int y) {
	bool found;
	for (int fr = 0; fr < parent.size(); fr++) {
		if (y == fr) continue;
		if (trees[y].size() != trees[fr].size()) continue;
		found = true;
		for (const auto &tr: trees[y]) {
			if (trees[fr].find(tr) == trees[fr].end()) {
				found = false;
				break;
			}
		}
		if (!found) continue;
		else {
			mergeByRank(fr, y);
			return;
		}
	}
}

int main() {
	int cas, T, P, p, t;
	char line[50];
	cin >> cas;
	while (cas--) {
		scanf("%d %d", &P, &T);
		getchar();
		parent.clear();
		rnk.clear();
		parent.assign(P, 0);
		rnk.assign(P, 0);
		unordered_set<int> empt;
		trees.assign(P, empt);
		numSets = P;
		for (int u = 0; u < P; u++) parent[u] = u;
		while (gets(line)) {
			if (strlen(line) == 0) break;
			sscanf(line, "%d %d", &p, &t);
			trees[p-1].insert(t-1);
		}
		for (int y = 0; y < P; y++) {
			findMerge(y);
		}
		cout << numSets << endl;
		if (cas) cout << "\n";
	}
	return 0;
}
