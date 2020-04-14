#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	long long int N;
	while(true) {
		cin >> N;
		if (!N) break;
		if (N > 6) cout << "Case " << t << ": " << ((N-3)*(N-3)+4)/12 << "\n";
		else if (N == 6) cout << "Case " << t << ": 1\n";
		else cout << "Case " << t << ": 0\n";
		t++;
	}
	return 0;
}
