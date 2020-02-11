#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int cur, i, temp;
	vector<int> nums;
	while(scanf("%d", &cur) == 1) {
		nums.push_back(cur);
		if (nums.size() == 1) {
			cout << nums[0] << endl;
			continue;
		} else if (nums.size() == 2) {
			cout << (nums[0]+nums[1])/2 << endl;
			sort(nums.begin(), nums.end());
			continue;
		}
		i = nums.size()-2;
		while (cur < nums[i]) {
			temp = nums[i];
			nums[i] = nums[i+1];
			nums[i+1] = temp;
			i--;
			if (i < 0) {
				break;
			}
		}
		if (nums.size() % 2 == 0) {
			cout << (nums[nums.size() / 2]+nums[nums.size() / 2 - 1])/2 << endl;
		} else {
			cout << nums[nums.size() / 2] << endl;
		}
	}
	return 0;
}
