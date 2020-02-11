#include <iostream>
#include <string>
using namespace std;

int main() {
	string cur;
	int N, tot;
	while(true) {
		cin >> cur;
		if (cur == "0") {
			break;
		}
		N = stoi(cur);
		while (N >= 10) {
			tot = 0;
			for (int i = 0; i < cur.length(); i++) {
				tot += cur[i] - '0';
			}
			N = tot;
			cur = to_string(N);
		}
		cout << N << endl;
	}
	return 0;
}
