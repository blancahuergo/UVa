#include <iostream>
#include <fstream>
#include <cfloat>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>
#include <climits>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<vvvl> vvvvl;
typedef vector<string> vs;
typedef pair<int, pii> triple;
#define fir first
#define sec second
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define all(v) v.begin(), v.end()

ll binPow(ll a, ll b, ll mod) {
	ll x = 1ll;
	while(b) {
		if (b&1) {
			x *= a;
			x %= mod;
		}
		a *= a;
		a %= mod;
		b >>= 1;
	}
	return x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	ll a, b, mod;
	cin >> T;
	while(T--) {
		cin >> a >> b >> mod;
		cout << binPow(a, b, mod) << "\n";
	}
	cin >> T;
	return 0;
}
