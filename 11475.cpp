#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string text;
	int best;
	bool wrong;
	while(cin >> text) {
		best = 1;
		for (int i = text.length() - 2; i >= 0; i--) {
			int j = i, k = text.length()-1;
			wrong = false;
			while(j < k) {
				if (text[j] != text[k]) {
					wrong = true;
					break;
				}
				j++;
				k--;
			}
			if (!wrong) best = text.length() - i;
		}
		cout << text;
		for (int c = text.length() - 1 - best; c >= 0; c--) cout << text[c];
		cout << "\n";
	}
	return 0;
}
