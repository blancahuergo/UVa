#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <limits>
using namespace std;

vector<int> nums;
vector<int> occ;
vector<int> st;

int left(int p) {
	return p*2;
}

int right(int p) {
	return p*2+1;
}

void build(int v, int start, int end) {
    if (start == end) {
        st[v] = occ[start];
    } else {
        int mid = (start + end) / 2;
        build(v*2, start, mid);
        build(v*2+1, mid+1, end);
        st[v] = max(st[v*2], st[v*2+1]);
    }
}

int max_query(int v, int start, int end, int l, int r) {
    if (l > r)
        return - numeric_limits<int>::infinity();
    if (l <= start && end <= r)
        return st[v];
    int mid = (start + end) / 2;
    return max(max_query(v*2, start, mid, l, min(r, mid)),
               max_query(v*2+1, mid+1, end, max(l, mid+1), r));
}

int max_occ(int A, int B, int N) {
	if (nums[A] == nums[B]) return B-A+1;
	int i, j, left_count, right_count;
	i = A;
	while(nums[A] == nums[i]) i++;
	j = B;
	while(nums[B] == nums[j]) j--;
	int ans_mid = max_query(1, 0, N-1, i, j);
	left_count = i - A;
	right_count = B - j;
	return max(max(ans_mid, left_count), right_count);
}

int main() {
	int N, Q, A, B;
	unordered_map<int, int> counts;
	while(true) {
		cin >> N;
		if (!N) break;
		cin >> Q;
		nums.clear();
		nums.assign(N, 0);
		for (int i = 0; i < N; i++) {
			cin >> nums[i];
		}
		counts.clear();
		for (int j = 0; j < N; j++) {
			if (counts.find(nums[j]) == counts.end()) {
				counts[nums[j]] = 1;
			} else {
				counts[nums[j]]++;
			}
		}
		occ.clear();
		occ.assign(N, 0);
		for (int j = 0; j < N; j++) {
			occ[j] = counts[nums[j]];
		}
		st.clear();
		st.assign(4*N, 0);
		build(1, 0, N-1);
		for (int h = 0; h < Q; h++) {
			cin >> A >> B;
			cout << max_occ(A-1, B-1, N) << endl;
		}
	}
	return 0;
}
