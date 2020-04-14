#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N;
	long long int DP[41];
	DP[0] = 1;
	DP[1] = 1;
	DP[2] = 5;
	for (int i = 3; i <= 40; i++) {
		DP[i] = 4*DP[i-2] + DP[i-1] + 2*DP[i-3];
	}
	cin >> T;
	while(T--) {
		cin >> N;
		cout << DP[N] << "\n";
	}
	return 0;
}
