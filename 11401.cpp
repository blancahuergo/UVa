#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	long long int N;
	unordered_map<long long int, long long int> ans;
	while(true) {
		cin >> N;
		if (N < 3) break;
		if (ans.find(N) == ans.end())
			ans[N] = (N-2)*N*(2*N-5)/24;
		cout << ans[N] << "\n";
	}
	return 0;
}
