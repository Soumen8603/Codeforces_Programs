#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    if(!(cin >> t)) return 0;
    while (t--) {
        int n; 
        cin >> n;
        int m = 2 * n;
        vector<int> a(m, 0);

        // Pointer to the next free slot to avoid rescanning from 0
        int next_free = 0;

        for (int x = n; x >= 1; --x) {
            // find first free position i
            while (next_free < m && a[next_free] != 0) ++next_free;
            int i = next_free;
            a[i] = x;

            // find the next free position j at step x from i
            int j = i + x;
            while (j < m && a[j] != 0) j += x;
            // Problem guarantees existence, so j < m holds
            a[j] = x;
        }

        for (int i = 0; i < m; ++i) {
            cout << a[i] << (i + 1 == m ? '\n' : ' ');
        }
    }
    return 0;
}