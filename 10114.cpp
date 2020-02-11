#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int dur, rec, mon, i;
	double down_pay, loan, val, car_val, owed, pay;
	while(true) {
		cin >> dur >> down_pay >> loan >> rec;
		if (dur < 0) {
			break;
		}
		double depr[dur+1];
		for (int i = 0; i < rec; i++) {
			cin >> mon >> val;
			for (int u = mon; u <= dur; u++) {
				depr[u] = val;
			}
		}
		car_val = (loan+down_pay)*(1-depr[0]);
		owed = loan;
		pay = loan/dur;
		i = 0;
		while (owed > car_val) {
			i++;
			owed -= pay;
			car_val *= (1-depr[i]);
			if (owed < car_val) {
				break;
			}
		}
		if (i == 1) {
			cout << "1 month\n";
		} else {
			cout << i << " months\n";
		}
	}
	return 0;
}
