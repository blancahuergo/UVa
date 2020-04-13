#include <iostream>
using namespace std;

int main() {
	int a, b, c, d, e;
	while(true) {
		cin >> a >> b >> c >> d >> e;
		if (!(a || b || c || d || e)) break;
		cout << a*b*c*d*d*e*e << "\n";
	}
	return 0;
}
