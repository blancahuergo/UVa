#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
int N, M;
vector<vector<ll>> DP;
vector<ll> nums;

ll calc() {
	// DP[numElements][numElementsInSet]
	DP.assign(N+1, vector<ll>(N+1, 0));
	DP[0][0] = 1;
	for (int n = 1; n <= N; n++) {
		DP[n][0] = 1;
		for (int k = 1; k <= n; k++) {
			DP[n][k] = (DP[n-1][k] + (DP[n-1][k-1]*nums[n-1])%M)%M;
		}
	}
	ll ret = 0;
	for (int i = 0; i <= N; i++) ret = max(ret, DP[N][i]);
	return ret;
}

int main() {
	while(true) {
		cin >> N >> M;
		if (!(N||M)) break;
		nums.assign(N, 0);
		for (int n = 0; n < N; n++) {
			cin >> nums[n];
			nums[n] %= M;
		}
		cout << calc() << "\n";
	}
	return 0;
}
