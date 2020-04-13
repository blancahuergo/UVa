#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(3);
	double x, y, c, low, high, mid, expW;
	while(cin >> x >> y >> c) {
		low = 0;
		high = min(x, y);
		while(fabs(low - high) > 1e-9) {
			mid = (low + high) / 2;
			expW = c*mid/sqrt(x*x - mid*mid) + c*mid/sqrt(y*y - mid*mid);
			if (expW > mid) {
				high = mid;
			} else {
				low = mid;
			}
		}
		cout << mid << "\n";
	}
	return 0;
}
