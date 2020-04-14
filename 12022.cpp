#include <iostream>
using namespace std;

int comb(int n, int r) {
	if (n == r || n == 0 || r == 0) return 1;
	return comb(n-1, r-1) + comb(n-1, r);
}

int main() {
	int A[12];
	A[0] = 1;
	for (int n = 2; n <= 12; n++) {
		A[n-1] = 0;
		for (int i = 0; i <= n-1; i++) {
			A[n-1] += comb(n-1, i)*A[n-i-1];
		}
	}
	int T, N;
	cin >> T;
	while(T--) {
		cin >> N;
		cout << A[N] << "\n";
	}
	return 0;
}
