#include <iostream>
using namespace std;

int main() {
	int N, last_r, last_s, min_dist;
	string s;
	while(true) {
		cin >> N;
		if (N == 0) {
			break;
		}
		cin >> s;
		min_dist = 2000001;
		last_r = -1;
		last_s = -1;
		for (int i = 0; i < N; i++) {
			if (s[i] == 'R') {
				if (last_s != -1) {
					if (i - last_s < min_dist) {
						min_dist = i - last_s;
					}
				}
				last_r = i;
			} else if (s[i] == 'D') {
				if (last_r != -1) {
					if (i - last_r < min_dist) {
						min_dist = i - last_r;
					}
				}
				last_s = i;
			} else if (s[i] == 'Z') {
				min_dist = 0;
			}
		}
		cout << min_dist << endl;
	}
	return 0;
}
