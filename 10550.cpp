#include <iostream>
using namespace std;

int main() {
	int a, b, c, d, res;
	while (scanf("%d %d %d %d", &a, &b, &c, &d), (a||b||c||d)) {
		res = 1080;
		if (a > b) {
			res += (a-b)*9;
		} else {
			res += (40+a-b)*9;
		}
		if (c > b) {
			res += (c-b)*9;
		} else {
			res += (40+c-b)*9;
		}
		if (c > d) {
			res += (c-d)*9;
		} else {
			res += (40+c-d)*9;
		}
		cout << res << endl;
	}
	return 0;
}
