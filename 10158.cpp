#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;
vector<int> rnk;
vector<int> enemies;
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
	int r_A, r_B;
	r_A = root(a);
	r_B = root(b);
	if (r_A == r_B) {
		return true;
	}
	if (enemies[r_A] != -1 && enemies[r_B] != -1 && (root(enemies[r_A]) == root(enemies[r_B]))) {
		return true;
	}
	else return false;
}

bool areEnemies(int a, int b) {
	if (areFriends(a, b)) return false;
	int r_A = root(a);
	int r_B = root(b);
	if (enemies[r_A] == -1 && enemies[r_B] == -1) return false;
	if (enemies[r_A] == -1) {
		return areFriends(r_A, enemies[r_B]);
	} else if (enemies[r_B] == -1) {
		return areFriends(r_B, enemies[r_A]);
	} else return enemies[r_A] == r_B || enemies[r_B] == r_A;
}

void setFriends(int a, int b) {
	int r_A = root(a);
	int r_B = root(b);
	if (areEnemies(a, b) || (enemies[r_A] != -1 && enemies[r_B] != -1 && areEnemies(enemies[r_A], enemies[r_B]))) {
		cout << "-1\n";
		return;
	}
	if (areFriends(a, b)) return;
	mergeByRank(a, b);
	if (enemies[r_A] != -1 && enemies[r_B] != -1) mergeByRank(enemies[r_A], enemies[r_B]);
	if (enemies[r_A] == -1 && enemies[r_B] != -1) enemies[r_A] = root(enemies[r_B]);
	else if (enemies[r_B] == -1 && enemies[r_A] != -1) enemies[r_B] = root(enemies[r_A]);
}

void setEnemies(int a, int b) {
	int r_A = root(a);
	int r_B = root(b);
	if (areFriends(a, b)) {
		cout << "-1\n";
		return;
	}
	if (enemies[r_A] != -1 && areEnemies(enemies[r_A], b)) {
		cout << "-1\n";
		return;
	}
	if (enemies[r_B] != -1 && areEnemies(enemies[r_B], a)) {
		cout << "-1\n";
		return;
	}
	if (areEnemies(a, b)) return;
	if (enemies[r_A] != -1) {
		mergeByRank(enemies[r_A], b);
	} else enemies[r_A] = r_B;
	if (enemies[r_B] != -1) {
		mergeByRank(enemies[r_B], a);
	} else enemies[r_B] = r_A;
}

int main() {
	int a, b, c;
	cin >> N;
	enemies.assign(N, -1);
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
