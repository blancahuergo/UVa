#include <iostream>
using namespace std;

typedef unsigned long long int ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	ll lo, hi, mid, N, M;
	cin >> T;
	while(T--) {
		cin >> N >> M;
		lo = 1;
		hi = N;
		while(true) {
			mid = (lo+hi)/2;
			if ((mid*(mid-1)/2 + N - mid) < M) lo = mid;
			else hi = mid;
			if (mid == (lo+hi)/2) break;
		}
		cout << N - hi << "\n";
	}
	return 0;
}
