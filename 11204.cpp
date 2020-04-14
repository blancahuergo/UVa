#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T, N, M, f;
	cin >> T;
	while(T--) {
		cin >> N >> M;
		vector<int> fav(N, 0);
		for (int m = 0; m < M; m++) {
			for (int n = 0; n < N; n++) {
				cin >> f;
				if (f == 1) fav[n]++;
			}
		}
		int ans = 1;
		for (int n = 0; n < N; n++) ans *= max(fav[n], 1);
		cout << ans << "\n";
	}
	return 0;
}
