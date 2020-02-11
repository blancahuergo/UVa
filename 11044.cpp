#include <iostream>
using namespace std;

int main() {
	int cases, a, b;
	cin >> cases;
	for (int u = 0; u < cases; u++) {
		cin >> a >> b;
		while ((a-2) % 3 > 0) {
			a++;
		}
		while ((b-2) % 3 > 0) {
			b++;
		}
		cout << (a-2)*(b-2)/9 << endl;
	}
	return 0;
}
