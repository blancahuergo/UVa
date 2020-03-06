#include <iostream>
#include <cstring>
using namespace std;

int DP[71][71][71];

int avg(int T, int N) {
	if (T % N == 0) return T/N;
	else return T/N + 1;
}

int Ways(int N, int T, int P) {
	if (T < P || avg(T, N) < P) return 0;
	if (N == 1) {
		if (T >= P) return 1;
		else return 0;
	}
	if (DP[N][T][P] != -1) return DP[N][T][P];
	int count = 0;
	for (int t = P; t <= T-P; t++) {
		count += Ways(N-1, t, P);
	}
	DP[N][T][P] = count;
	return count;
}

int main() {
	int K, N, T, P;
	cin >> K;
	memset(DP, -1, sizeof DP);
	while(K--) {
		cin >> N >> T >> P;
		cout << Ways(N, T, P) << endl;
	}
	return 0;
}
