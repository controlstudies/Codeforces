#include<iostream>
using namespace std;
int main() {
    long t;
    cin>>t;
    while(t--){
        int n,b;
        cin>>n;
        int a[n];

        for (int i=0;i<n;i++){
            cin>>a[i];
            if(i!=0 && i!=n-1){
                if(a[i]==-1) a[i]=0;
            }
        }

        if(a[0]==-1 || a[n-1]==-1) {
            if(a[0]==-1 && a[n-1]!=-1) a[0]=a[n-1];
            else if(a[n-1]==-1 && a[0]!=-1) a[n-1]=a[0];
            else if(a[0]==-1 && a[n-1]==-1){
                a[0]=0;
                a[n-1]=0;
            }
            b=0;
        } 
        else {
            b = abs(a[n-1] - a[0]);
        }

        cout<<b<<endl;
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}
