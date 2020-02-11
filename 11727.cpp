#include <iostream>
using namespace std;

int main() {
	int cases, a, b, c, temp;
	cin >> cases;
	for (int u = 0; u < cases; u++) {
		cin >> a >> b >> c;
		if (a > c) {
            temp = a;
            a = c;
            c = temp;
		}
        if (a > b) {
            temp = a;
            a = b;
            b = temp;
        }
        if (b > c) {
            temp = b;
            b = c;
            c = temp;
        }
		cout << "Case " << u+1 << ": " << b << endl;
	}
	return 0;
}
