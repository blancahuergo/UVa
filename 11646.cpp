#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(8);
	double A, B, L, W, arc, lo, hi, ang;
	string colon;
	int cas = 1;
	while(cin >> A >> colon >> B) {
		lo = 0;
		hi = 400;
		ang = atan(B/A) * 180/M_PI;
		while(hi - lo > 1e-9) {
			L = (lo + hi)/2.0;
			W = B*L/A;
			arc = sqrt(W*W + L*L)*ang / 180 * M_PI;
			if (L + arc < 200) lo = L;
			else hi = L;
		}
		cout << "Case " << cas << ": " << L << " " << B*L/A << "\n";
		cas++;
	}
	return 0;
}
