#include<iostream>
#include<vector>
#include<climits>
#include<string.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i = 0;i < n;i++){
            cin>>a[i];
        }
       
        vector<int>mini(n);
        vector<int>maxi(n);
        int minvalue = a[0];
        int maxvalue = a[n-1];
        mini[0] = a[0];
        for(int i = 1;i < n;i++){
            if(a[i] < minvalue){
                mini[i] = a[i];
                minvalue = a[i];
            }
            else{
                mini[i] = minvalue;
            }
        }
        maxi[n-1] = a[n-1];
        for(int i = n-2;i >= 0;i--){
            if(a[i]>maxvalue){
               maxi[i]=a[i];
                maxvalue = a[i];
            }
            else{
                maxi[i] = maxvalue;
            }
        }
        
        
        for(int i = 0;i < n;i++){
            cout<<(a[i] == mini[i] || a[i] == maxi[i])?'1':'0';
        }

        cout<<endl;
       
        
    }
}