#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	string cur;
	int pos;
	while(true) {
		vector<stack<string>> piles;
		cin >> cur;
		if (cur == "#") break;
		stack<string> cur_stack;
		cur_stack.push(cur);
		piles.push_back(cur_stack);
		for (int i = 1; i < 52; i++) {
			cin >> cur;
			if (piles.size() >= 3 && (cur[0] == piles[piles.size()-3].top()[0] || cur[1] == piles[piles.size()-3].top()[1])) {
				piles[piles.size()-3].push(cur);
				pos = piles.size()-3;
				while (pos < piles.size()) {
					if (pos >= 3 && (piles[pos].top()[0] == piles[pos-3].top()[0] || piles[pos].top()[1] == piles[pos-3].top()[1])) {
						piles[pos-3].push(piles[pos].top());
						piles[pos].pop();
						if (piles[pos].empty()) {
							piles.erase(piles.begin() + pos);
						}
						pos -= 3;
					} else if (pos >= 1 && (piles[pos].top()[0] == piles[pos-1].top()[0] || piles[pos].top()[1] == piles[pos-1].top()[1])) {
						piles[pos-1].push(piles[pos].top());
						piles[pos].pop();
						if (piles[pos].empty()) {
							piles.erase(piles.begin() + pos);
						}
						pos--;
					} else pos++;
				}
			} else if (cur[0] == piles[piles.size()-1].top()[0] || cur[1] == piles[piles.size()-1].top()[1]) {
				piles[piles.size()-1].push(cur);
				pos = piles.size()-1;
				while (pos < piles.size()) {
					if (pos >= 3 && (piles[pos].top()[0] == piles[pos-3].top()[0] || piles[pos].top()[1] == piles[pos-3].top()[1])) {
						piles[pos-3].push(piles[pos].top());
						piles[pos].pop();
						if (piles[pos].empty()) {
							piles.erase(piles.begin() + pos);
						}
						pos -= 3;
					} else if (pos >= 1 && (piles[pos].top()[0] == piles[pos-1].top()[0] || piles[pos].top()[1] == piles[pos-1].top()[1])) {
						piles[pos-1].push(piles[pos].top());
						piles[pos].pop();
						if (piles[pos].empty()) {
							piles.erase(piles.begin() + pos);
						}
						pos--;
					} else pos++;
				}
			} else {
				stack<string> c_stack;
				c_stack.push(cur);
				piles.push_back(c_stack);
			}
		}
		if (piles.size() == 1) {
			cout << "1 pile remaining: 52" << endl;
		} else {
			cout << piles.size() << " piles remaining:";
			for (int i = 0; i < piles.size(); i++) {
				cout << " " << piles[i].size();
			}
			cout << "\n";
		}
	}
	return 0;
}
