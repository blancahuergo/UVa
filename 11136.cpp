#include <iostream>
#include <set>
using namespace std;

int main() {
	int days, bills, val;
	long long cost;
	while(true) {
		cin >> days;
		if (!days) break;
		multiset<int> vals;
		multiset<int>::iterator it_max, it_min;
		cost = 0;
		for (int u = 0; u < days; u++) {
			cin >> bills;
			for (int i = 0; i < bills; i++) {
				cin >> val;
				vals.insert(val);
			}
			it_max = vals.end();
			--it_max;
			it_min = vals.begin();
			cost += (*it_max - *it_min);
			vals.erase(it_min);
			vals.erase(it_max);
		}
		cout << cost << endl;
	}
	return 0;
}
