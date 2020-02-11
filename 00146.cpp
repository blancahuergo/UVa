#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string s;
	while(true) {
		cin >> s;
		if (s == "#") {
			break;
		}
		if (next_permutation(begin(s), end(s))) {
			cout << s << endl;
		} else {
			cout << "No Successor" << endl;
		}
	}
	return 0;
}
