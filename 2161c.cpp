#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {long long t;
    cin>>t;
    while(t--){
    int n;
    long long X;
    cin >> n >> X;

    vector<long long> price(n);
    for (int i = 0; i < n; i++) cin >> price[i];

    sort(price.begin(), price.end());

    long long s = 0;     // total spent so far
    long long tp = 0;    // total bonus points
    long long ll = 0;    // current loyalty level

    for (int i = 0; i < n; i++) {
        long long currll = (s + price[i]) / X;   // loyalty level if we buy this item
        if (currll > ll) tp += price[i];         // if loyalty increases, add bonus
        ll = currll;                             // update loyalty
        s += price[i];                            // update total spent
    }

    cout << tp << endl;

    for (int i = 0; i < n; i++) cout << price[i] << " ";
    cout << endl;
}
}