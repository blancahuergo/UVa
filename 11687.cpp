#include <iostream>
using namespace std;

int main() {
	string x, x_l;
	int i;
	while(true) {
		cin >> x_l;
		if (x_l == "END") {
			break;
		}
		i = 1;
		x = to_string(x_l.length());
		while(x != x_l) {
			x_l = x;
			x = to_string(x_l.length());
			i++;
		}
		cout << i << endl;
	}
	return 0;
}
