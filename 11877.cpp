#include <iostream>
using namespace std;

int main() {
	int n, empty, full, drank;
	while(true) {
		cin >> n;
		if (!n) break;
		empty = n;
		full = 0;
		drank = 0;
		while(empty >= 3) {
			full = empty/3;
			empty = full + (empty%3);
			drank += full;
		}
		if (empty == 2) {
			drank++;
		}
		cout << drank << endl;
	}
	return 0;
}
