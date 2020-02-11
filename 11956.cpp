#include <iostream>
using namespace std;

string hex(int i) {
	string ret = "";
	if (i / 16 < 10) {
		ret += to_string(i/16);
	} else {
		ret.push_back('A' + (i/16 - 10));
	}
	i %= 16;
	if (i < 10) {
		ret += to_string(i);
	} else {
		ret.push_back('A' + (i-10));
	}
	return ret;
}

int main() {
	int T, pointer;
	string st;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> st;
		pointer = 0;
		int nums[100];
		cout << "Case " << (i+1) << ":";
		for (int n = 0; n < 100; n++) {
			nums[n] = 0;
		}
		for (int j = 0; j < st.length(); j++) {
			if (st[j] == '<') {
				pointer--;
				if (pointer == -1) {
					pointer = 99;
				}
			} else if (st[j] == '>') {
				pointer++;
				pointer %= 100;
			} else if (st[j] == '+') {
				nums[pointer]++;
				nums[pointer] %= 256;
			} else if (st[j] == '-') {
				nums[pointer]--;
				if (nums[pointer] == -1) {
					nums[pointer] = 255;
				}
			}
		}
		for (int k = 0; k < 100; k++) {
			cout << " " << hex(nums[k]);
		}
		cout << endl;
	}
	return 0;
}
