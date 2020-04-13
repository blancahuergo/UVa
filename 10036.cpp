#include <iostream>
#include <vector>
using namespace std;

vector<int> nums;
vector<vector<bool>> DP;
int N, K;

bool calc() {
	DP.assign(N+1, vector<bool>(K, false));
	DP[0][0] = 1;
	for (int n = 1; n <= N; n++) {
		for (int k = 0; k < K; k++) {
			DP[n][(((k + nums[n-1]) % K) + K) % K] = DP[n][(((k + nums[n-1]) % K) + K) % K] || DP[n-1][k];
			DP[n][(((k - nums[n-1]) % K) + K) % K] = DP[n][(((k - nums[n-1]) % K) + K) % K] || DP[n-1][k];
		}
	}
	return DP[N][0] > 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while(T--) {
		cin >> N >> K;
		nums.assign(N, 0);
		for (int n = 0; n < N; n++) cin >> nums[n];
		if (calc()) cout << "Divisible\n";
		else cout << "Not divisible\n";
	}
	return 0;
}
