#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	int people, amount, gifts, gift;
	string nam, fr;
	vector<string> names;
	bool leave = false;
	while(cin >> people) {
		map<string, int> balance;
		names.clear();
		for (int i = 0; i < people; i++) {
			cin >> nam;
			balance[nam] = 0;
			names.push_back(nam);
		}
		for (int i = 0; i < people; i++) {
			cin >> nam;
			cin >> amount >> gifts;
			if (gifts == 0) continue;
			gift = amount/gifts;
			balance[nam] -= (gifts*gift);
			for (int u = 0; u < gifts; u++) {
				cin >> fr;
				balance[fr] += gift;
			}
		}
		if (leave) {
			printf("\n");
		}
		for (int t = 0; t < people; t++) {
			cout << names[t] << " " << balance[names[t]] << endl;
		}
		leave = true;
	}
	return 0;
}
