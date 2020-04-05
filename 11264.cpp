#include <iostream>
using namespace std;

int main() {
	int T, N, taken;
	long long curTot;
	cin >> T;
	while(T--) {
		cin >> N;
		int coins[N];
		taken = 1;
		for (int n = 0; n < N; n++) {
			cin >> coins[n];
		}
		curTot = 1LL;
		for (int i = 1; i < N-1; i++) {
			if (curTot + coins[i] < coins[i+1]) {
				curTot += coins[i];
				taken++;
			}
		}
		taken++;
		cout << taken << "\n";
	}
	return 0;
}
