#include <iostream>
#include <cstring>
using namespace std;

char equiv(char c) {
	if (c == 'W') return 'Q';
	if (c == 'E') return 'W';
	if (c == 'R') return 'E';
	if (c == 'T') return 'R';
	if (c == 'Y') return 'T';
	if (c == 'U') return 'Y';
	if (c == 'I') return 'U';
	if (c == 'O') return 'I';
	if (c == 'P') return 'O';
	if (c == 'S') return 'A';
	if (c == 'D') return 'S';
	if (c == 'F') return 'D';
	if (c == 'G') return 'F';
	if (c == 'H') return 'G';
	if (c == 'J') return 'H';
	if (c == 'K') return 'J';
	if (c == 'L') return 'K';
	if (c == 'X') return 'Z';
	if (c == 'C') return 'X';
	if (c == 'V') return 'C';
	if (c == 'B') return 'V';
	if (c == 'N') return 'B';
	if (c == 'M') return 'N';
	return '0';
}

int main() {
	char str[10001];
	while(gets(str)) {
		for (int c = 0; c < strlen(str); c++) {
			if (str[c] >= 'A' && str[c] <= 'Z') str[c] = equiv(str[c]);
			else if (str[c] == ',') str[c] = 'M';
			else if (str[c] == '.') str[c] = ',';
			else if (str[c] == '/') str[c] = '.';
			else if (str[c] == ';') str[c] = 'L';
			else if (str[c] == '\'') str[c] = ';';
			else if (str[c] == '\\') str[c] = ']';
			else if (str[c] == ']') str[c] = '[';
			else if (str[c] == '[') str[c] = 'P';
			else if (str[c] == '=') str[c] = '-';
			else if (str[c] == '-') str[c] = '0';
			else if (str[c] == '0') str[c] = '9';
			else if (str[c] > '1' && str[c] <= '9') str[c]--;
			else if (str[c] == '1') str[c] = '`';
		}
		puts(str);
	}
	return 0;
}
