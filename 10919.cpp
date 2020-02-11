#include <iostream>
#include <set>
using namespace std;

int main() {
	int courses, categs, cat_courses, cat_min, cur, cat_count;
	bool meets;
	while(true) {
		cin >> courses;
		if (courses == 0) {
			break;
		}
		cin >> categs;
		set<int> fred;
		for (int i = 0; i < courses; i++) {
			cin >> cur;
			fred.insert(cur);
		}
		meets = true;
		for (int j = 0; j < categs; j++) {
			cin >> cat_courses >> cat_min;
			cat_count = 0;
			for (int u = 0; u < cat_courses; u++) {
				cin >> cur;
				if (fred.count(cur)) {
					cat_count++;
				}
			}
			if (cat_count < cat_min) {
				meets = false;
			}
		}
		if (meets) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}
	return 0;
}
