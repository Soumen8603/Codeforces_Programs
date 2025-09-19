#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        if (n == 1) {
            cout << "YES\n";
            continue;
        }
        long long l = 0,r = n  - 1;
        bool check = true;
        long long curr = 1;
        while(curr <= n){
            if(p[l] == curr){
                l++;
                curr++;
                continue;
            }
            if(p[r] == curr){
                r--;
                curr++;
                continue;
            }
            check = false;
            break;
        }
        if(check) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    return 0;
}