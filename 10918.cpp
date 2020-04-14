#include <iostream>
using namespace std;

int main() {
	int N;
	int DP[16];
	DP[0] = 1;
	DP[1] = 1;
	for (int i = 2; i <= 15; i++)
		DP[i] = 4*DP[i-1] - DP[i-2];
	while(true) {
		cin >> N;
		if (N == -1) break;
		if (N == 0) cout << "1\n";
		else if (N%2 == 0) cout << 4*DP[N/2] - DP[N/2 - 1] << "\n";
		else cout << "0\n";
	}
	return 0;
}
