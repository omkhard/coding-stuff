//
//Author: beegeepee
//
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n=0,a,b,lessPrice = 0;
        cin>>n>>a>>b;
        if (n==1){
            cout<<a<<endl;
        }else{
            if(b<(2*a) && n%2!=0){
                lessPrice = b*((n-1)/2);
                lessPrice += a;
                cout<<lessPrice<<endl;
            }
            else if(b<(2*a) && n%2==0){
                lessPrice = b*n/2;
                cout<<lessPrice<<endl;
            }
            else if(b>=(2*a)){
                lessPrice = n*a;
                cout<<lessPrice<<endl;
            }
        }    
    }
    return 0;
}