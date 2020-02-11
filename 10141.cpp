#include <iostream>
#include <limits>
using namespace std;

int main() {
	int req, prop, met_req, cas, max_met;
	double price, max_p;
	string prop_name, max_prop, st;
	cas = 1;
	while(true) {
		scanf("%d %d\n", &req, &prop);
		if (!(req || prop)) {
			break;
		}
		if (cas > 1) {
			cout << "\n";
		}
		for (int u = 0; u < req; u++) {
			getline(cin, st);
		}
		max_met = -1;
		max_p = numeric_limits<double>::max();
		max_prop = "none";
		for (int u = 0; u < prop; u++) {
			getline(cin, prop_name);
			scanf("%f %d\n", &price, &met_req);
			if (met_req > max_met) {
				max_met = met_req;
				max_prop = prop_name;
				max_p = price;
			} else if (met_req == max_met && price < max_p) {
				max_met = met_req;
				max_prop = prop_name;
				max_p = price;
			}
			for (int i = 0; i < met_req; i++) {
				getline(cin, st);
			}
		}
		cout << "RFP #" << cas << "\n";
		cout << max_prop << "\n";
		cas++;
	}
	return 0;
}
