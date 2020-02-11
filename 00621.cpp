#include <iostream>
using namespace std;

int main() {
	int N;
	string s;
	cin >> N;
	for (int u = 0; u < N; u++) {
		cin >> s;
		if (s == "78" || s == "1" || s == "4") {
			cout << "+" << endl;
		} else if (s[0] == '9' && s[s.length()-1] == '4') {
			cout << "*" << endl;
		} else if (s[s.length()-2] == '3' && s[s.length()-1] == '5') {
			cout << "-" << endl;
		} else {
			cout << "?" << endl;
		}
	}
	return 0;
}
