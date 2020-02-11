#include <iostream>
#include <vector>
using namespace std;

int main() {
	int B, N, D, C, V, cur;
	vector<int> reserves;
	bool possible;
	while (true) {
		cin >> B >> N;
		if (!(B || N)) {
			break;
		}
		reserves.clear();
		for (int i = 0; i < B; i++) {
			cin >> cur;
			reserves.push_back(cur);
		}
		for (int u = 0; u < N; u++) {
			cin >> D >> C >> V;
			reserves[D-1] -= V;
			reserves[C-1] += V;
		}
		possible = true;
		for (int y = 0; y < B; y++) {
			if (reserves[y] < 0) {
				possible = false;
			}
		}
		if (possible) {
			printf("S\n");
		} else {
			printf("N\n");
		}
	}
	return 0;
}
