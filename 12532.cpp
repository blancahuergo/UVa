#include <iostream>
#include <vector>
using namespace std;

vector<int> st;
vector<int> A;

int left(int p) {
	return p << 1;
}

int right(int p) {
	return (p << 1) + 1;
}

void build(int p, int L, int R) {
	if (L == R) {
		if (A[L] > 0) st[p] = 1;
		else if (A[L] < 0) st[p] = -1;
		else st[p] = 0;
	} else {
		build(left(p), L, (L+R)/2);
		build(right(p), (L+R)/2 + 1, R);
		st[p] = st[left(p)]*st[right(p)];
	}
}

int query(int p, int L, int R, int i, int j) {
	if (i > R || j < L) return -2;
	if (i <= L && j >= R) return st[p];
	int p1 = query(left(p), L, (L+R)/2, i, j);
	int p2 = query(right(p), (L+R)/2 + 1, R, i, j);
	if (p1 == -2) return p2;
	if (p2 == -2) return p1;
	return p1*p2;
}

void update(int p, int L, int R, int x, int val) {
	if (L == R) {
		A[x] = val;
		if (val > 0) st[p] = 1;
		else if (val < 0) st[p] = -1;
		else st[p] = 0;
	} else {
		if (x >= L && x <= (L+R)/2) {
			update(left(p), L, (L+R)/2, x, val);
		} else {
			update(right(p), (L+R)/2 + 1, R, x, val);
		}
		st[p] = st[left(p)]*st[right(p)];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K, i, j, res;
	string com;
	while(cin >> N >> K) {
		A.assign(N, 0);
		st.assign(4*N, 0);
		for (int u = 0; u < N; u++) {
			cin >> A[u];
		}
		build(1, 0, N-1);
		for (int t = 0; t < K; t++) {
			cin >> com >> i >> j;
			if (com[0] == 'P') {
				res = query(1, 0, N-1, i-1, j-1);
				if (res == 1) cout << "+";
				else if (res == -1) cout << "-";
				else cout << "0";
			} else {
				update(1, 0, N-1, i-1, j);
			}
		}
		cout << "\n";
	}
	return 0;
}
