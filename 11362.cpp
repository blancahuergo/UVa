#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> phones;

bool check(int A, int B) {
	if (phones[A].length() > phones[B].length()) return false;
	for (int i = 0; i < phones[A].length(); i++) {
		if (phones[A][i] != phones[B][i]) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N;
	cin >> T;
	while(T--) {
		cin >> N;
		phones = vector<string>(N);
		for (int n = 0; n < N; n++) cin >> phones[n];
		sort(phones.begin(), phones.end());
		bool bad = false;
		for (int i = 0; i < N; i++) {
			for (int j = i+1; j < N; j++) {
				bad = check(i, j);
				if (bad) break;
			}
			if (bad) break;
		}
		if (bad) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}
