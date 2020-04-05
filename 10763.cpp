#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	vector<int> orig, tar;
	while(true) {
		cin >> N;
		if (!N) break;
		orig.assign(N, 0);
		tar.assign(N, 0);
		for (int n = 0; n < N; n++) {
			cin >> orig[n] >> tar[n];
		}
		sort(orig.begin(), orig.end());
		sort(tar.begin(), tar.end());
		bool cor = true;
		for (int n = 0; n < N; n++) {
			if (orig[n] != tar[n]) {
				cor = false;
				break;
			}
		}
		if (cor) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
