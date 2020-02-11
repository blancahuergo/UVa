#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
	int cas, fields, g_num, b_num, cur;
	vector<int> g_bat;
	vector<int> b_bat;
	cin >> cas;
	for (int c = 0; c < cas; c++) {
		cin >> fields >> g_num >> b_num;
		multiset<int> green;
		multiset<int> blue;
		multiset<int>::iterator g_max, b_max;
		for (int p = 0; p < g_num; p++) {
			cin >> cur;
			green.insert(cur);
		}
		for (int p = 0; p < b_num; p++) {
			cin >> cur;
			blue.insert(cur);
		}
		while ((green.size() > 0) && (blue.size() > 0)) {
			g_bat.clear();
			b_bat.clear();
			for (int y = 0; y < fields; y++) {
				if (green.size() == 0 || blue.size() == 0) {
					break;
				}
				g_max = green.end();
				g_max--;
				b_max = blue.end();
				b_max--;
				if (*g_max > *b_max) {
					g_bat.push_back(*g_max - *b_max);
				} else if (*b_max > *g_max) {
					b_bat.push_back(*b_max - *g_max);
				}
				green.erase(g_max);
				blue.erase(b_max);
			}
			for (int a = 0; a < g_bat.size(); a++) {
				green.insert(g_bat[a]);
			}
			for (int a = 0; a < b_bat.size(); a++) {
				blue.insert(b_bat[a]);
			}
		}
		if (c) cout << "\n";
		if (green.size() > 0) {
			cout << "green wins" << endl;
			while (green.size()) {
				g_max = green.end();
				g_max--;
				cout << *g_max << endl;
				green.erase(g_max);
			}
		} else if (blue.size() > 0) {
			cout << "blue wins" << endl;
			while(blue.size()) {
				b_max = blue.end();
				b_max--;
				cout << *b_max << endl;
				blue.erase(b_max);
			}
		} else {
			cout << "green and blue died" << endl;
		}
	}
	return 0;
}
