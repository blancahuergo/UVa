#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main() {
	string s;
	vector<int> last_change;
	int queries, a, b, temp;
	int cas = 1;
	while (cin >> s) {
		last_change.clear();
		last_change.push_back(0);
		for (int i = 1; i < s.length(); i++) {
			if (s[i] == s[i-1]) {
				last_change.push_back(last_change[i-1]);
			} else {
				last_change.push_back(i);
			}
		}
		cin >> queries;
		cout << "Case " << cas << ":\n";
		for (int i = 0; i < queries; i++) {
			cin >> a >> b;
			if (a > b) {
				temp = b;
				b = a;
				a = temp;
			}
			if (last_change[a] == last_change[b]) {
				cout << "Yes" << endl;
			} else {
				cout << "No" << endl;
			}
		}
		cas++;
	}
	return 0;
}
