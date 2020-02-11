#include <iostream>
using namespace std;

int main() {
	int a, b, opt1, opt2, temp;
	while(true) {
		cin >> a >> b;
		if (a == -1 && b == -1) {
			break;
		}
		opt1 = abs(b-a);
		if (b < a) {
			temp = b;
			b = a;
			a = temp;
		}
		// a is smaller than b
		opt2 = 100-b+a;
		cout << min(opt1, opt2) << endl;
	}
	return 0;
}
