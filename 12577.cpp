#include <iostream>
using namespace std;

int main() {
	string s;
	int cas;
	cas = 1;
	while(true) {
		cin >> s;
		if (s == "*") {
			break;
		} else if (s == "Hajj") {
			cout << "Case " << cas << ": Hajj-e-Akbar" << endl;
		} else {
			cout << "Case " << cas << ": Hajj-e-Asghar" << endl;
		}
		cas++;
	}
	return 0;
}
