#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

vector<pair<int, int>> points;

int distSq(pair<int, int> p_A, pair<int, int> p_B) {
	return (p_A.first - p_B.first)*(p_A.first - p_B.first) + (p_A.second - p_B.second)*(p_A.second - p_B.second);
}

double dist_arr(vector<int> ord) {
	double ret = 0.0;
	for (int i = 0; i < ord.size()-1; i++)
		ret += sqrt((double) distSq(points[ord[i]], points[ord[i+1]]))+16;
	return ret;
}

void TSP(int N, int cas) {
	cout << setprecision(2) << fixed;
	double res = 20000000000000.0, d, tot_dist=0.0, cur_dist;
	vector<int> nums;
	vector<int> best_perm;
	for (int i = 0; i < N; i++) nums.push_back(i);
	do {
		d = dist_arr(nums);
		if (d < res) {
			res = d;
			best_perm = nums;
		}
	} while(next_permutation(nums.begin(), nums.end()));
	cout << "**********************************************************\nNetwork #" << cas << "\n";
	for (int i = 0; i < best_perm.size()-1; i++) {
		cur_dist = sqrt((double) distSq(points[best_perm[i]], points[best_perm[i+1]]))+16;
		cout << "Cable requirement to connect (" << points[best_perm[i]].first << "," << points[best_perm[i]].second;
		cout << ") to (" << points[best_perm[i+1]].first << "," << points[best_perm[i+1]].second << ") is " << cur_dist << " feet.\n";
	}
	cout << "Number of feet of cable required is " << res << ".\n";
}

int main() {
	int N, cas;
	cas = 1;
	while(true) {
		cin >> N;
		if (!N) break;
		points.assign(N, {0, 0});
		for (int n = 0; n < N; n++) {
			cin >> points[n].first >> points[n].second;
		}
		TSP(N, cas);
		cas++;
	}
	return 0;
}
