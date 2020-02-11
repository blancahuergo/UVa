#include <iostream>
using namespace std;

int main() {
	int n, count;
	bool going_up;
	while(true) {
		cin >> n;
		if (!n) {
			break;
		}
		int wave[n];
		for (int i = 0; i < n; i++) {
			cin >> wave[i];
		}
		count = 0;
		for (int j = 1; j < n-1; j++) {
			if (wave[j] > wave[j-1] && wave[j] > wave[j+1]) {
				count++;
			} else if (wave[j] < wave[j-1] && wave[j] < wave[j+1]) {
				count++;
			}
		}
		if (wave[0] > wave[n-1] && wave[0] > wave[1]) {
			count++;
		} else if (wave[0] < wave[n-1] && wave[0] < wave[1]) {
			count++;
		}
		if (wave[n-1] > wave[n-2] && wave[n-1] > wave[0]) {
			count++;
		} else if (wave[n-1] < wave[n-2] && wave[n-1] < wave[0]) {
			count++;
		}
		cout << count << endl;
	}
	return 0;
}
