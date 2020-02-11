#include <iostream>
using namespace std;

int main() {
	int cas, a, b, c, cur;
	cin >> cas;
	cur = 1;
	for (int u = 0; u < cas; u++) {
		cin >> a >> b >> c;
		if (a <= 20 && b <= 20 && c <= 20) {
			cout << "Case " << cur << ": good" << endl;
		} else {
			cout << "Case " << cur << ": bad" << endl;
		}
		cur++;
	}
	return 0;
}
