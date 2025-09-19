#include<iostream>
#include<vector>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,j,k;
        cin>>n>>j>>k;
        vector<int>a(n);
        for(int i = 0;i < n;i++){
            cin>>a[i];
        }
        if(k >= 2){
            cout<<"YES"<<endl;
        }
        else{
            int maxi = -1;
            for(int i = 0;i < n;i++){
                maxi = max(maxi,a[i]);

            }
            if(a[j-1] == maxi){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
}