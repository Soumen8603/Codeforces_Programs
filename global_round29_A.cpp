#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long x,y;
        cin>>x>>y;
       if(x < y){
        cout<<2<<endl;
        continue;
       }
       else if(x == y){
        cout<<-1<<endl;
        continue;
       }
       else if(y == 1){
        cout<<-1<<endl;
       }
       else{
        if(1 + y + 1 <= x){
            cout<<3<<endl;
        }

        else{
            cout<<-1<<endl;
        }
       }
            
        
    }
    return 0;
}