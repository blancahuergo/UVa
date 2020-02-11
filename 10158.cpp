#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> parent;
vector<int> rnk;
vector<unordered_set<int>> enemies;
int N;

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
	if (rnk[r_a] > rnk[r_b]) {
		parent[r_b] = r_a;
	} else if (rnk[r_b] > rnk[r_a]) {
		parent[r_a] = r_b;
	} else {
		parent[r_a] = r_b;
		rnk[r_b]++;
	}
}

bool areFriends(int a, int b) {
	if (root(a) == root(b)) return true;
	// if any common enemy, merge(a,b) and return true; otherwise return false
	bool fr = false;
	if (enemies[a].size() < enemies[b].size()) {
		for (const auto& en: enemies[a]) {
			if (enemies[b].find(en) != enemies[b].end()) {
				fr = true;
				break;
			}
		}
	} else {
		for (const auto& en: enemies[b]) {
			if (enemies[a].find(en) != enemies[a].end()) {
				fr = true;
				break;
			}
		}
	}
	if (fr) {
		mergeByRank(a, b);
		return true;
	}
	return false;
}

bool areEnemies(int a, int b) {
	// rewrite following rest of rules
	if (areFriends(a, b)) return false;
	if (enemies[a].find(b) != enemies[a].end()) return true;
	if (enemies[b].find(a) != enemies[b].end()) return true;
	// if any of a's enemies is b's friend return false
	for (const auto& en: enemies[a]) {
		if (areFriends(b, en)) return false;
	}
	// if any of b's enemies is a's friend return false
	for (const auto& en: enemies[b]) {
		if (areFriends(a, en)) return false;
	}
	return false;
}

// Set functions correct as long as check functions check all rules
void setEnemies(int a, int b) {
	if (areFriends(a, b)) {
		cout << "-1\n";
		return;
	}
	if (areEnemies(a, b)) return;
	enemies[a].insert(b);
	enemies[b].insert(a);
}

void setFriends(int a, int b) {
	if (areEnemies(a, b)) {
		cout << "-1\n";
		return;
	}
	if (areFriends(a, b)) return;
	mergeByRank(a, b);
}

int main() {
	int a, b, c;
	cin >> N;
	unordered_set<int> empt;
	enemies.assign(N, empt);
	rnk.assign(N, 0);
	parent.assign(N, 0);
	for (int u = 0; u < N; u++) parent[u] = u;
	while(true) {
		cin >> c >> a >> b;
		if (!c) break;
		if (c == 1) {
			setFriends(a, b);
		} else if (c == 3) {
			if (areFriends(a, b)) cout << "1\n";
			else cout << "0\n";
		} else if (c == 2) {
			setEnemies(a, b);
		} else {
			if (areEnemies(a, b)) cout << "1\n";
			else cout << "0\n";
		}
	}
	return 0;
}
