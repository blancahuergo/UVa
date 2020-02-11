#include <iostream>
using namespace std;

string code(char c) {
	if (c == 'B' || c == 'F' || c == 'P' || c == 'V') {
		return "1";
	} else if (c == 'C' || c == 'G' || c == 'J' || c == 'K' || c == 'Q' || c == 'S'|| c == 'X' || c == 'Z') {
		return "2";
	} else if (c == 'D' || c == 'T') {
		return "3";
	} else if (c == 'L') {
		return "4";
	} else if (c == 'M' || c == 'N') {
		return "5";
	} else if (c == 'R') {
		return "6";
	}
	return "";
}

int main() {
	string word;
	string output;
	string last_code;
	string cur_code;
	while (getline(cin, word)) {
		output = "";
		last_code = "-";
		for (int i = 0; i < word.length(); i++) {
			cur_code = code(word[i]);
			if (cur_code != last_code) {
				output += cur_code;
				last_code = cur_code;
			}
		}
		cout << output << endl;
	}
	return 0;
}
