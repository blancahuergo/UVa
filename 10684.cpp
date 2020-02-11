#include <iostream>
using namespace std;

int main() {
	int N, cur_sum, cur, max_sum;
	while(true) {
		cin >> N;
		if (!N) break;
		cur_sum = 0;
		max_sum = -1;
		for (int y = 0; y < N; y++) {
			cin >> cur;
			cur_sum += cur;
			if (cur_sum > max_sum) max_sum = cur_sum;
			if (cur_sum < 0) cur_sum = 0;
		}
		if (max_sum > 0) cout << "The maximum winning streak is " << max_sum << "." << endl;
		else cout << "Losing streak." << endl;
	}
	return 0;
}
