#include <iostream>
using namespace std;

int main() {
	int cas = 1, N;
	while(true) {
		cin >> N;
		if (!N) break;
		cout << "Case " << cas << ": " << N/2 << "\n";
		cas++;
	}
	return 0;
}
