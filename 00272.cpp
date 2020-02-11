#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	bool ch = true;
	while (getline(cin, str)) {
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '"') {
				if (ch) {
					ch = false;
					str = str.substr(0, i) + "``" + str.substr(i+1, str.length() - i);
				} else {
					ch = true;
					str = str.substr(0, i) + "''" + str.substr(i+1, str.length() - i);
				}
			}
		}
		cout << str << endl;
	}
	return 0;
}
