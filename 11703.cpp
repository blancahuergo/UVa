#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int DP[1000001];

int first(int N) {
	return (int) (N - sqrt((double) N));
}

int second(int N) {
	return (int) log((double) N);
}

int third(int N) {
	return (int) ((double)N)*(sin((double)N)*sin((double)N));
}

int Ways(int N) {
	if (DP[N] != -1) return DP[N];
	int val = ((Ways(first(N)) % 1000000) + (Ways(second(N)) % 1000000) + (Ways(third(N)) % 1000000)) % 1000000;
	DP[N] = val;
	return DP[N];
}

int main() {
	int N;
	memset(DP, -1, sizeof DP);
	DP[0] = 1;
	while(true) {
		cin >> N;
		if (N == -1) break;
		cout << Ways(N) << endl;
	}
	return 0;
}
