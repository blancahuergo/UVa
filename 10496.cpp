#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

vector<pair<int, int>> points;

int dist(pair<int, int> p_A, pair<int, int> p_B) {
	return abs(p_A.first - p_B.first) + abs(p_A.second - p_B.second);
}

int dist_arr(vector<int> ord) {
	int ret = 0;
	for (int i = 0; i < ord.size()-1; i++)
		ret += dist(points[ord[i]], points[ord[i+1]]);
	ret += dist(points[ord[ord.size()-1]], points[ord[0]]);
	return ret;
}

void TSP(int N) {
	int res = INT_MAX;
	vector<int> nums;
	for (int i = 0; i < N; i++) nums.push_back(i);
	do {
		res = min(res, dist_arr(nums));
	} while(next_permutation(nums.begin(), nums.end()));
	cout << "The shortest path has length " << res << endl;
}

int main() {
	int T, R, C, s_R, s_C, N;
	cin >> T;
	while(T--) {
		cin >> C >> R;
		cin >> s_C >> s_R;
		cin >> N;
		points.assign(N+1, {0, 0});
		for (int n = 0; n < N; n++) {
			cin >> points[n].second >> points[n].first;
		}
		points[N].first = s_C;
		points[N].second = s_R;
		TSP(N+1);
	}
	return 0;
}
