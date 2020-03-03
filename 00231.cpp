#include <iostream>
#include <vector>
using namespace std;

long long longest(vector<int> nums) {
	long long max_len = 1, cur_max_len;
	long long LIS[nums.size()];
	LIS[0] = 1;
	for (int i = 1; i < nums.size(); i++) {
		cur_max_len = 1;
		for (int j = 0; j < i; j++) {
			if (nums[j] > nums[i]) cur_max_len = max(cur_max_len, LIS[j]+1);
		}
		LIS[i] = cur_max_len;
		max_len = max(max_len, LIS[i]);
	}
	return max_len;
}

int main() {
	int N;
	vector<int> nums;
	int cas = 1;
	while(true) {
		cin >> N;
		if (N == -1) break;
		nums.clear();
		nums.push_back(N);
		while(true) {
			cin >> N;
			if (N == -1) break;
			nums.push_back(N);
		}
		if (cas > 1) cout << "\n";
		cout << "Test #" << cas << ":" << endl;
		cout << "  maximum possible interceptions: " << longest(nums) << endl;
		cas++;
	}
	return 0;
}
