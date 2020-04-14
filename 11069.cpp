#include <iostream>
using namespace std;

int main() {
	int N;
	int DP[77];
	DP[0] = 0;
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 2;
	for (int i = 4; i <= 76; i++)
		DP[i] = DP[i-2] + DP[i-3];
	while(cin >> N)
		cout << DP[N] << "\n";
	return 0;
}
