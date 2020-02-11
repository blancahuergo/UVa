#include <iostream>
using namespace std;

int main() {
	int N, B, H, b, W;
	long cur, p;
	while (scanf("%d %d %d %d", &N, &B, &H, &W) != EOF) {
		cur = 5000000001;
		for (int i = 0; i < H; i++) {
			cin >> p;
			for (int j = 0; j < W; j++) {
				cin >> b;
				if (b >= N && N*p < cur) {
					cur = N*p;
				}
			}
		}
		if (cur <= B) {
			cout << cur << endl;
		} else {
			cout << "stay home" << endl;
		}
	}
	return 0;
}
