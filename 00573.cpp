#include <iostream>
using namespace std;

int main() {
	int H, U, D, F, day;
	double cur_h, fat, climb;
	bool success;
	while (true) {
		scanf("%d %d %d %d", &H, &U, &D, &F);
		if (H == 0) {
			break;
		}
		cur_h = 0;
		fat = (F/(double)100)*U;
		climb = U;
		day = 1;
		success = false;
		while(true) {
			if (climb >= 0) cur_h += climb;
			if (cur_h > H) {
				success = true;
				break;
			}
			cur_h -= D;
			if (cur_h < 0) {
				break;
			}
			climb -= fat;
			day++;
		}
		if (success) {
			cout << "success on day " << day << endl;
		} else {
			cout << "failure on day " << day << endl;
		}
	}
	return 0;
}
