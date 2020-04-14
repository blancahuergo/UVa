#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long int N;
	int T;
	cin >> T;
	while(T--) {
		cin >> N;
		if (N <= 3) cout << "0\n";
		else cout << (N-2)*N*(2*N-5)/24 << "\n";
	}
	return 0;
}
