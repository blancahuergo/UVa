#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, limit, rate, tot, ans;
	vector<int> M, A;
	while(true) {
		cin >> N >> limit >> rate;
		if (!(N || limit || rate)) break;
		M.assign(N, 0);
		A.assign(N, 0);
		for (int n = 0; n < N; n++) {
			cin >> M[n];
		}
		for (int n = 0; n < N; n++) {
			cin >> A[n];
		}
		sort(M.begin(), M.end(), greater<int>());
		sort(A.begin(), A.end());
		tot = 0;
		for (int n = 0; n < N; n++) {
			if (A[n] + M[n] > limit) {
				tot += A[n]+M[n]-limit;
			}
		}
		ans = tot*rate;
		cout << ans << "\n";
	}
	return 0;
}
