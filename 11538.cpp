#include <iostream>
using namespace std;

typedef long long int ll;

int main() {
	ll R, C, ans, mn, mx;
	while(true) {
		cin >> R >> C;
		if (!(R||C)) break;
		mn = min(R, C);
		mx = max(R, C);
		ans = C*R*(R-1) + R*C*(C-1);
		for (ll i = 2; i < mn; i++) {
			ans += 4*i*(i-1);
		}
		ans += 2*(mx-mn+1)*mn*(mn-1);
		cout << ans << "\n";
	}
	return 0;
}
