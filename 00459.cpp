#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;
vector<int> rnk;
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

int main() {
	int cas, N;
	string sz;
	cin >> cas;
	for (int c = 0; c < cas; c++) {
		cin >> sz;
		cin.ignore();
		N = int(sz[0] -'A')+1;
		numSets = N;
		parent.clear();
		rnk.clear();
		parent.assign(N, 0);
		rnk.assign(N, 0);
		for (int u = 0; u < N; u++) parent[u] = u;
		while(getline(cin, sz) && sz != "") {
			mergeByRank(int(sz[0] - 'A'), int(sz[1] - 'A'));
		}
		if (c) cout << "\n";
		cout << numSets << endl;
	}
	return 0;
}
