#include <iostream>
#include <vector>
using namespace std;

vector<int> DP;

void fillDP() {
	DP.assign(10001, 2e9);
	DP[1] = 1;
	DP[0] = 0;
	for (int n = 2; n <= 10000; n++) {
		for (int j = 1; j*j <= n; j++) {
			DP[n] = min(DP[n], DP[n - j*j]+1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	fillDP();
	int T, N;
	cin >> T;
	while(T--) {
		cin >> N;
		cout << DP[N] << '\n';
	}
	return 0;
}
