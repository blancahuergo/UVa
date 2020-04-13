#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long int ll;
vector<vector<ll>> C;

ll comb(int n, int r) {
	if (n == 0 || r == 0 || n == r) return 1;
	if (C[n][r] != 0) return C[n][r];
	ll ans = comb(n-1, r-1) + comb(n-1, r);
	return C[n][n-r] = C[n][r] = ans;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	C.assign(101, vector<ll>(101, 0));
	int N, M;
	while(true) {
		cin >> N >> M;
		if (!(N || M)) break;
		cout << N << " things taken " << M << " at a time is " << comb(N, M) << " exactly.\n";
	}
	return 0;
}
