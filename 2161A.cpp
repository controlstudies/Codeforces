#include<bits/stdc++.h>
using namespace std;
int main(){
    long t;cin>>t;
    while(t--){
        long n;cin>>n;
        long long a;cin>>a;
        vector<long long> marbel(n);
        vector<long long> alice(n);      // changed from long double to long long
        long count_left=0,count_right=0;
        long long bob;
        for(long i=0;i<n;i++){
            cin>>marbel[i];
            alice[i]=marbel[i]-a;
           if(alice[i]>0) count_right++;
           else if(alice[i]<0) count_left++;
        }if(count_left>count_right) {cout<<a-1<<endl;continue;}
        if(count_right>count_left) {cout<<a+1<<endl;continue;}
        if(count_left==count_right) {cout<<a+1<<endl;continue;}
    }}