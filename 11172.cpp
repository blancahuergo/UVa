#include <iostream>
int cas, A, B;
cin >> cas;
while(cas--) {
    cin >> A >> B;
    if (A > B) cout << ">\n";
    else if (A < B) cout << "<\n";
    else cout << "=\n";
}