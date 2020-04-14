#include <iostream>
using namespace std;

int main() {
	long long int a, b;
	int t = 1;
	while(true) {
		cin >> a >> b;
		if (!(a||b)) break;
		cout << "Case " << t << ": " << a*b*(a-1)*(b-1)/4 << "\n";
		t++;
	}
	return 0;
}
