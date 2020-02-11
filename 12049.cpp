#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	int cas, N, M, cur;
	cin >> cas;
	for (int c = 0; c < cas; c++) {
		cin >> N >> M;
		multiset<int> setA;
		multiset<int> setB;
		for (int n = 0; n < N; n++) {
			cin >> cur;
			setA.insert(cur);
		}
		for (int n = 0; n < M; n++) {
			cin >> cur;
			setB.insert(cur);
		}
		multiset<int> intersection;
		set_intersection(setA.begin(), setA.end(), setB.begin(), setB.end(), inserter(intersection, intersection.begin()));
		cout << (N+M - 2*intersection.size()) << endl;
	}
	return 0;
}
