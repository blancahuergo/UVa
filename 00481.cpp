#include <iostream>
#include <vector>
using namespace std;

vector<int> nums;

int ceil(vector<int> tail, int l, int r, int key) {
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

void longestGreedy() {
	int N = nums.size();
	int alt_ind, alt_len=0;
	vector<int> tail;
	tail.assign(N, 0);
	vector<int> empty;
	vector<vector<int>> seq;
	seq.assign(N, empty);
	int len = 1, ind;
	tail[0] = nums[0];
	seq[0] = {0};
	for (int i = 1; i < N; i++) {
		// Case 1: nums[i] is the new smallest value
		if (nums[i] < tail[0]) {
			tail[0] = nums[i];
			seq[0] = {i};
		}
		// Case 2: nums[i] extends the longest sequence, as it is the new largest number.
		else if (nums[i] > tail[len - 1]) {
			tail[len] = nums[i];
			seq[len] = seq[len-1];
			seq[len].push_back(i);
			len++;
		}
		// Case 3: nums[i] is somewhere in between new smallest and new largest
		else {
			ind = ceil(tail, -1, len-1, nums[i]);
			tail[ind] = nums[i];
			seq[ind] = seq[ind-1];
			seq[ind].push_back(i);
		}
		if (len >= 2 && nums[i] > nums[seq[len-1][seq[len-1].size()-2]]) {
			alt_ind = i;
			alt_len = len;
		}
	}
	if (alt_len == len && nums[alt_ind] > nums[seq[len-1][seq[len-1].size()-2]]) {
		seq[len-1][seq[len-1].size()-1] = alt_ind;
	}
	cout << len << endl;
	cout << "-\n";
	for (int j = 0; j < seq[len-1].size(); j++) {
		cout << nums[seq[len-1][j]] << endl;
	}
}


int main() {
	int N;
	while(cin >> N) {
		nums.push_back(N);
	}
	longestGreedy();
	return 0;
}
