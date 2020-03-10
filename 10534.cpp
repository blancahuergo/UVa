#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

vector<int> nums;

int ceil(int tail[], int l, int r, int key) {
	int mid;
	while (r - l > 1) {
		mid = l + (r-l)/2;
		if (tail[mid] >= key) {
			r = mid;
		} else if (tail[mid] < key) {
			l = mid;
		}
	}
	return r;
}

int Wavio(int N) {
	int LISF[N], tail[N], len, ind;
	len = 1;
	LISF[0] = 1;
	tail[0] = nums[0];
	for (int i = 1; i < N; i++) {
		if (nums[i] < tail[0]) {
			tail[0] = nums[i];
			LISF[i] = 1;
		} else if (nums[i] > tail[len-1]) {
			tail[len] = nums[i];
			LISF[i] = len+1;
			len++;
		} else {
			ind = ceil(tail, -1, len-1, nums[i]);
			tail[ind] = nums[i];
			LISF[i] = ind+1;
		}
	}
	reverse(nums.begin(), nums.end());
	vector<int> LISB(N);
	int tail2[N];
	len = 1;
	LISB[0] = 1;
	tail2[0] = nums[0];
	for (int i = 1; i < N; i++) {
		if (nums[i] < tail2[0]) {
			tail2[0] = nums[i];
			LISB[i] = 1;
		} else if (nums[i] > tail2[len-1]) {
			tail2[len] = nums[i];
			LISB[i] = len+1;
			len++;
		} else {
			ind = ceil(tail2, -1, len-1, nums[i]);
			tail2[ind] = nums[i];
			LISB[i] = ind+1;
		}
	}
	reverse(LISB.begin(), LISB.end());
	int maxl = 1;
	for (int i = 0; i < N; i++) {
		maxl = max(maxl, 2*min(LISB[i], LISF[i]) - 1);
	}
	return maxl;
}

int main() {
	int N;
	while(scanf("%d", &N) != EOF) {
		nums.assign(N, 0);
		for(int n = 0; n < N; n++) {
			scanf("%d", &nums[n]);
		}
		printf("%d\n", Wavio(N));
	}
	return 0;
}
