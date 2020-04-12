#include <iostream>
#include <cstring>
using namespace std;

typedef long long int ll;

int N;
ll a[21][21];

ll calc(int i, int j) {
	if (a[i][j] != -1) return a[i][j];
	if (i < j) {
		ll ret = 0;
		for (int k = i; k < j; k++)
			ret = max(ret, calc(i, k) + calc(k+1, j));
		return a[i][j] = ret;
	} else {
		ll cur = 0, ext = 0;
		for (int k = i+1; k <= N; k++)
			cur = max(cur, calc(k, 1) + calc(k, j));
		for (int k = 1; k < j; k++)
			ext = max(ext, calc(i, k) + calc(N, k));
		return a[i][j] = cur+ext;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a_n1;
	while(cin >> N >> a_n1) {
		memset(a, -1, sizeof a);
		a[N][1] = a_n1;
		cout << calc(1, N) << "\n";
	}
	return 0;
}
