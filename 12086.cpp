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
	if (L == R) st[p] = A[L];
	else {
		build(left(p), L, (L+R)/2);
		build(right(p), (L+R)/2 + 1, R);
		st[p] = st[left(p)] + st[right(p)];
	}
}

int rsq(int p, int L, int R, int i, int j) {
	if (i > R || j < L) return -1;
	if (i <= L && j >= R) return st[p];
	int p1 = rsq(left(p), L, (L+R)/2, i, j);
	int p2 = rsq(right(p), (L+R)/2 + 1, R, i, j);
	if (p1 == -1) return p2;
	if (p2 == -1) return p1;
	return p1+p2;
}

void update(int p, int L, int R, int x, int r) {
	if (L == R) {
		A[x] = r;
		st[p] = r;
	} else {
		if (L <= x && x <= (L+R)/2) update(left(p), L, (L+R)/2, x, r);
		else update(right(p), (L+R)/2 + 1, R, x, r);
		st[p] = st[left(p)] + st[right(p)];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, i, j, x, r;
	string com;
	int cas = 1;
	while(true) {
		cin >> N;
		if (!N) break;
		st.assign(4*N, 0);
		A.assign(N, 0);
		for (int u = 0; u < N; u++) {
			cin >> A[u];
		}
		build(1, 0, N-1);
		if (cas > 1) cout << "\n";
		cout << "Case " << cas << ":\n";
		while(true) {
			cin >> com;
			if (com[0] == 'E') break;
			else if (com[0] == 'S') {
				cin >> x >> r;
				update(1, 0, N-1, x-1, r);
			} else {
				cin >> i >> j;
				cout << rsq(1, 0, N-1, i-1, j-1) << endl;
			}
		}
		cas++;
	}
	return 0;
}
