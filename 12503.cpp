#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T, N, st, p;
	string inst;
	vector<string> saved;
	cin >> T;
	for (int u = 0; u < T; u++) {
		cin >> N;
		p = 0;
		saved.clear();
		for (int i = 0; i < N; i++) {
			cin >> inst;
			if (inst == "LEFT") {
				saved.push_back("LEFT");
				p--;
			} else if (inst == "RIGHT") {
				saved.push_back("RIGHT");
				p++;
			} else {
				cin >> inst;
				cin >> st;
				saved.push_back(saved[st-1]);
				if (saved[st-1] == "LEFT") {
					p--;
				} else {
					p++;
				}
			}
		}
		cout << p << endl;
	}
	return 0;
}
