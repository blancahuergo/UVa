#include <iostream>
using namespace std;

int main() {
	int cases, n, res;
	string a;
	cin >> cases;
	for (int u = 0; u < cases; u++) {
		cin >> n;
		res = ((n*63+7492)*5-498);
		if (res > 0) {
			res %= 100;
			res /= 10;
			cout << res << endl;
		} else {
			a = to_string(res);
			cout << a[a.length - 2] << endl;
		}
	}
	return 0;
}
