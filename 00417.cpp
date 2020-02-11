#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	unordered_map<string, int> codes;
	int count = 1;
	string word, code;
	for (char i = 'a'; i <= 'z'; i++) {
		code = i;
		codes[code] = count;
		count++;
	}
	for (char a = 'a'; a <= 'z'; a++) {
		for (char b = a+1; b <= 'z'; b++) {
			code = a;
			code += b;
			codes[code] = count;
			count++;
		}
	}
	for (char a = 'a'; a <= 'z'; a++) {
		for (char b = a+1; b <= 'z'; b++) {
			for (int c = b+1; c <= 'z'; c++) {
				code = a;
				code += b;
				code += c;
				codes[code] = count;
				count++;
			}
		}
	}
	for (char a = 'a'; a <= 'z'; a++) {
			for (char b = a+1; b <= 'z'; b++) {
				for (char c = b+1; c <= 'z'; c++) {
					for (char d = c+1; d <= 'z'; d++) {
						code = a;
						code += b;
						code += c;
						code += d;
						codes[code] = count;
						count++;
					}
				}
			}
	}
	for (char a = 'a'; a <= 'z'; a++) {
		for (char b = a+1; b <= 'z'; b++) {
			for (char c = b+1; c <= 'z'; c++) {
				for (char d = c+1; d <= 'z'; d++) {
					for (char e = d+1; e <= 'z'; e++) {
						code = a;
						code += b;
						code += c;
						code += d;
						code += e;
						codes[code] = count;
						count++;
					}
				}
			}
		}
	}
	while(cin >> word) {
		if (codes.find(word) != codes.end()) {
			cout << codes[word] << endl;
		} else {
			cout << "0\n";
		}
	}
	return 0;
}
