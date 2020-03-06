#include <iostream>
#include <cstring>
using namespace std;

int DP[101][101];

int Ways(int N, int K) {
	if (K == 0) return 0;
	if (K == 1 || N == 0) {
		DP[N][K] = 1;
		return 1;
	}
	if (DP[N][K] != -1) return DP[N][K];
	int count = 0;
	for (int i = 0; i <= N; i++) {
		count += (Ways(i, 1)%1000000)*(Ways(N-i, K-1)%1000000);
		count %= 1000000;
	}
	DP[N][K] = count;
	return count;
}

int main() {
	int N, K;
	memset(DP, -1, sizeof DP);
	while(true) {
		cin >> N >> K;
		if (!(N||K)) break;
		cout << Ways(N, K) << endl;
	}
	return 0;
}
