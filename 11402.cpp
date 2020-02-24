#include <iostream>
#include <vector>
using namespace std;

/*
 * lazy[p] = 0 -> reset
 * lazy[p] = 1 -> set
 * lazy[p] = -1 -> flip
 * lazy[p] = -2 -> do nothing
 */

vector<long> st;
vector<int> A;
vector<int> lazy;

int left(int p) {
	return p << 1;
}

int right(int p) {
	return (p << 1) + 1;
}

int flip(int l) {
	if (l == -2) return -1;
	else if (l == -1) return -2;
	else return !l;
}

void propag(int p, int L, int R) {
	if (lazy[p] == -2) return;
	else if (L == R) {
		if (lazy[p] == -1) st[p] = !(st[p]);
		else st[p] = lazy[p];
	} else {
		if (lazy[p] == 0) {
			st[p] = 0;
			lazy[left(p)] = 0;
			lazy[right(p)] = 0;
		} else if (lazy[p] == 1) {
			st[p] = R - L + 1;
			lazy[left(p)] = 1;
			lazy[right(p)] = 1;
		} else {
			st[p] = (R - L + 1) - st[p];
			lazy[left(p)] = flip(lazy[left(p)]);
			lazy[right(p)] = flip(lazy[right(p)]);
		}
	}
	lazy[p] = -2;
}

void build(int p, int L, int R) {
	if (L == R) {
		st[p] = A[L];
	}
	else {
		build(left(p), L, (L+R)/2);
		build(right(p), (L+R)/2 + 1, R);
		st[p] = st[left(p)] + st[right(p)];
	}
}

int query(int p, int L, int R, int i, int j) {
	if (i > R || j < L) return -3;
	propag(p, L, R);
	if (i <= L && j >= R) return st[p];
	int p1 = query(left(p), L, (L+R)/2, i, j);
	int p2 = query(right(p), (L+R)/2 + 1, R, i, j);
	if (p1 == -3) return p2;
	if (p2 == -3) return p1;
	return p1+p2;
}

void set_buc(int p, int L, int R, int a, int b) {
	// set pirates between a and b to 1
	propag(p, L, R);
	if (a > R || b < L) return;
	if (a == b) {
		st[p] = 1;
	} else if (a <= L && b >= R) {
		st[p] = R - L + 1;
		lazy[left(p)] = lazy[right(p)] = 1;
	} else {
		set_buc(left(p), L, (L+R)/2, a, b);
		set_buc(right(p), (L+R)/2+1, R, a, b);
		st[p] = st[left(p)] + st[right(p)];
	}
}

void set_barb(int p, int L, int R, int a, int b) {
	// set pirates between a and b to 0
	propag(p, L, R);
	if (a > R || b < L) return;
	if (a == b) {
		st[p] = 0;
		lazy[p] = -2;
	} else if (a <= L && b >= R) {
		st[p] = 0;
		lazy[left(p)] = lazy[right(p)] = 0;
	} else {
		set_barb(left(p), L, (L+R)/2, a, b);
		set_barb(right(p), (L+R)/2+1, R, a, b);
		st[p] = st[left(p)] + st[right(p)];
	}
}

void set_inv(int p, int L, int R, int a, int b) {
	// invert pirates between a and b
	propag(p, L, R);
	if (a > R || b < L) return;
	if (a == b) {
		st[p] = !(st[p]);
		return;
	} else if (a <= L && b >= R) {
		st[p] = (R - L + 1) - st[p];
		lazy[left(p)] = flip(lazy[left(p)]);
		lazy[right(p)] = flip(lazy[right(p)]);
		return;
	}
	set_inv(left(p), L, (L+R)/2, a, b);
	set_inv(right(p), (L+R)/2+1, R, a, b);
	st[p] = st[left(p)] + st[right(p)];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, M, times, count, Q, a, b, quests;
	string com, pir;
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		cin >> M;
		count = 0;
		A.assign(1024010, 0);
		for (int m = 0; m < M; m++) {
			cin >> times;
			cin >> pir;
			for (int u = 0; u < times; u++) {
				for (int p = 0; p < pir.length(); p++) {
					A[count] = pir[p] - '0';
					count++;
				}
			}
		}
		st.clear();
		lazy.clear();
		st.assign(4*count, 0);
		lazy.assign(4*count, -2);
		build(1, 0, count-1);
		cin >> Q;
		quests = 1;
		cout << "Case " << cas << ":\n";
		for (int q = 0; q < Q; q++) {
			cin >> com >> a >> b;
			if (com[0] == 'F') {
				set_buc(1, 0, count-1, a, b);
			} else if (com[0] == 'E') {
				set_barb(1, 0, count-1, a, b);
			} else if (com[0] == 'I') {
				set_inv(1, 0, count-1, a, b);
			} else {
				cout << "Q" << quests << ": " << query(1, 0, count-1, a, b) << endl;
				quests++;
			}
		}
	}
	return 0;
}
