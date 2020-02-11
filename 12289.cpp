#include <iostream>
using namespace std;

int main() {
	int cases, one, two;
	cin >> cases;
	string n;
	for (int u = 0; u < cases; u++) {
		cin >> n;
		if (n.length() == 5) {
			cout << 3 << endl;
		} else {
			one = 0;
			two = 0;
			if (n[0] == 'o') {
				one++;
			} else if (n[0] == 't') {
				two++;
			}
			if (n[1] == 'n') {
				one++;
			} else if (n[1] == 'w') {
				two++;
			}
			if (n[2] == 'e') {
				one++;
			} else if (n[2] == 'o') {
				two++;
			}
			if (one > two) {
				cout << 1 << endl;
			} else {
				cout << 2 << endl;
			}
		}
	}
	return 0;
}
