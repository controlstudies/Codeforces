#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<long long,long long> store; // cache: a[i] -> smallest j
    int t;
    if(!(cin>>t)) return 0;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n);
        bool hasOdd = false;
        for(int i=0;i<n;i++){
            cin >> a[i];
            if(a[i] % 2 != 0) hasOdd = true;
        }

        if(hasOdd){
            cout << 2 << '\n'; // if any odd present, answer is 2
            continue;
        }

        long long minSoFar = LLONG_MAX;
        for(int i=0;i<n;i++){
            long long val = a[i];
            if(store.count(val)){
                minSoFar = min(minSoFar, store[val]);
                continue;
            }
            long long found = LLONG_MAX;
            // try j from 2 up to min(a[i]/2+1, minSoFar-1)
            long long upper = val/2 + 1;
            if(minSoFar != LLONG_MAX) upper = min(upper, minSoFar - 1);

            for(long long j = 2; j <= upper+2; ++j){
                if(std::gcd(j, val) == 1){
                    found = j;
                    store[val] = j;
                    break;
                }
            }
            if(found != LLONG_MAX) minSoFar = min(minSoFar, found);
        }

        if(minSoFar == LLONG_MAX) cout << -1 << '\n'; // no j found for any element (unlikely)
        else cout << minSoFar << '\n';
    }
}
