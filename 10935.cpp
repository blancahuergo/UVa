#include <iostream>
#include <queue>
using namespace std;

int main() {
	int num, cur;
	vector<int> discards;
	while(true) {
		cin >> num;
		if (!num) {
			break;
		}
		if (num == 1) {
			cout << "Discarded cards:" << endl;
			cout << "Remaining card: 1" << endl;
			continue;
		}
		queue<int> cards;
		for (int i = 1; i <= num; i++) {
			cards.push(i);
		}
		discards.clear();
		while(cards.size() > 1) {
			discards.push_back(cards.front());
			cards.pop();
			if (cards.size() > 1) {
				cur = cards.front();
				cards.pop();
				cards.push(cur);
			}
		}
		cout << "Discarded cards: ";
		for (int i = 0; i < discards.size()-1; i++) {
			cout << discards[i] << ", ";
		}
		cout << discards[discards.size()-1] << endl;
		cout << "Remaining card: " << cards.front() << endl;
	}
	return 0;
}
