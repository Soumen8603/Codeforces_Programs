#include<iostream>
#include<vector>
using namespace std;
void solve(){
    int t;
    cin>>t;
    int index;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>v(n);
        bool hasresult = false;
        for(int i = 0;i < n;i++){
            cin>>v[i];
        }

        for(int i = 0;i < n;i++){
            bool flag = true;
            for(int j = 0;j < n;j++){
                if(j==i)continue;
                if((v[j] % k) == (v[i] % k)){
                    break;
                    flag = false;
                }
            }
            if(flag == true){
                hasresult = true;
                index = i+1;
                break;
            }
        }
        if(hasresult){
            cout<<"YES\n";
            cout<<index;
            cout<<"\n";
        }
        else{
            cout<<"No\n";
        }
    }
}
int main()
{
    solve();
    return 0;
}