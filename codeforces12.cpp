
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; string s;
        cin >> n >> s;
        if (n % 2) { cout << -1 << '\n'; continue; }

        int half = n / 2;
        int openTot = 0, openOdd = 0, openEven = 0; // 1-based parity
        for (int i = 0; i < n; ++i) if (s[i] == '(') {
            ++openTot;
            ((i + 1) & 1) ? ++openOdd : ++openEven;
        }
        int D = openEven - openOdd;

        if ((openTot & 1) != (half & 1) || D < -half || D > half - 2 || ((half + D) & 1)) {
            cout << -1 << '\n';
            continue;
        }

        int e = (half + D) / 2; // target opens on even positions, 0..half-1
        string t; t.reserve(n);
        t.push_back('(');
        for (int i = 0; i < e; ++i) { t.push_back('('); t.push_back(')'); }
        for (int i = 0; i < half - e - 1; ++i) { t.push_back(')'); t.push_back('('); }
        t.push_back(')');
        cout << t << '\n';
    }
    return 0;
}
