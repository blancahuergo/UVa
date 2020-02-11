#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N;
	long cur;
	long long tot, cost;
	while(true) {
		cin >> N;
		if (!N) break;
		priority_queue<long> nums;
		for (int u = 0; u < N; u++) {
			cin >> cur;
			nums.push(-1*cur);
		}
		cost = 0;
		tot = 0;
		while(nums.size() > 1) {
			tot = nums.top()*-1;
			nums.pop();
			tot += nums.top()*-1;
			nums.pop();
			cost += tot;
			nums.push(tot*-1);
		}
		cout << cost << endl;
	}
	return 0;
}
