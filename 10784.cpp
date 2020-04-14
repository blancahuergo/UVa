#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long int N, A;
	int t = 1;
	while(true) {
		cin >> A;
		if (!A) break;
		A *= 2;
		for (N = sqrt(A); N <= A; N++) {
			if (N * (N-3) >= A) break;
		}
		cout << "Case " << t << ": " << max(4ll, N) << "\n";
		t++;
	}
	return 0;
}
